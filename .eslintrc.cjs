module.exports = {
	root: true,
	extends: ['custom'],
	settings: {
		next: {
			rootDir: ['apps/*/'],
		},
	},
	parserOptions: {
		tsconfigRootDir: __dirname,
		project: './tsconfig.project.json',
	},
}
