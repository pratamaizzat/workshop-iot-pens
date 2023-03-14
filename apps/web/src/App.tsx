import React from 'react'
import mqtt, { MqttClient } from 'mqtt/dist/mqtt'

export default function Home() {
	const [input, setInput] = React.useState('')
	const [payload, setPayload] = React.useState('00000000')
	const [client, setClient] = React.useState<MqttClient | null>(null)
	const [connectionStatus, setConnectionStatus] = React.useState<
		'Connecting' | 'Connected' | 'Disconnect' | 'Reconnecting'
	>('Disconnect')

	React.useEffect(() => {
		if (!client) {
			const c = mqtt.connect(`wss://mqtt.dinojantan.com:8883`, {
				clientId: `workshop-iot-pens-2023-${new Date().getTime()}`,
				keepalive: 0,
				connectTimeout: 4000,
				clean: true,
			})
			setConnectionStatus('Connecting')
			setClient(c)
		}
	}, [client])

	React.useEffect(() => {
		if (client) {
			client.on('connect', () => {
				setConnectionStatus('Connected')
			})
			client.on('error', (err) => {
				console.error('Connection error: ', err)
				client.end()
			})
			client.on('reconnect', () => {
				setConnectionStatus('Reconnecting')
			})
			client.on('message', (topic, message) => {
				const p = { topic, message: message.toString() }
				setPayload(p.message)
			})
			client.subscribe('/test/device', { qos: 0 }, (error) => {
				if (error) {
					console.log('Subscribe to topics error', error)
				}
			})
		}
	}, [client])

	const handlePublish = (evt: React.MouseEvent<HTMLFormElement>) => {
		evt.preventDefault()
		if (client) {
			client.publish('/test/device', input.slice(0, 8), { qos: 0 }, (error) => {
				if (error) {
					console.log('Publish error: ', error)
				}
			})
		}
	}

	return (
		<main
			aria-labelledby="titlePage"
			className="w-[100svw] h-[100svh] bg-[#f0f0f0] grid place-items-center"
		>
			<section className="flex flex-col gap-10 w-full max-w-[600px]">
				<div>
					<h3 id="titlePage" className="text-2xl font-bold text-center">
						Workshop IOT PENS 2023
					</h3>
					<p className="text-center mt-3">
						MQTT status:{' '}
						<span
							className={`font-semibold ${connectionStatus === 'Connected' && 'text-green-500'}`}
						>
							{connectionStatus}
						</span>
					</p>
				</div>
				<div className="flex gap-3 flex-wrap items-center justify-center my-9">
					{payload
						.slice(0, 8)
						.split('')
						.map((p) => (
							<div
								key={Math.random()}
								className={`w-[50px] h-[50px] ${
									p === '1' ? 'bg-green-400' : 'bg-red-400'
								} rounded-full`}
							/>
						))}
				</div>
				<form className="p-4" onSubmit={handlePublish}>
					<div className="h-[50px] flex w-full items-center border-2 rounded-lg overflow-hidden border-gray-400">
						<input
							className="flex-1 h-full border-none outline-none px-3 bg-transparent"
							type="text"
							name="publish"
							id="publish"
							placeholder="Publish payload"
							value={input}
							onChange={(evt) => setInput(evt.target.value)}
						/>
						<button
							className="min-w-[50px] w-[100px] h-full bg-gray-400 font-semibold"
							type="submit"
						>
							Send
						</button>
					</div>
				</form>
			</section>
		</main>
	)
}
