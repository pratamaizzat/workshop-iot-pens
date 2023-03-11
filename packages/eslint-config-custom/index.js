module.exports = {
	env: {
		browser: true,
		es2017: true,
		node: true,
	},
	extends: [
		'next',
		'turbo',
		'eslint:recommended',
		'plugin:@typescript-eslint/recommended',
		'airbnb-base',
		'airbnb-typescript/base',
		'plugin:prettier/recommended',
	],
	plugins: ['@typescript-eslint', 'import-no-duplicates-prefix-resolved-path'],
	settings: {
		'import/parsers': {
			'@typescript-eslint/parser': ['.cjs', '.js', '.ts', '.tsx'],
		},
		'import/resolver': {
			typescript: {
				alwaysTryTypes: true,
			},
		},
	},
	rules: {
		'@next/next/no-html-link-for-pages': 'off',
		'arrow-body-style': ['error', 'as-needed'],
		'prefer-arrow-callback': ['error', { allowNamedFunctions: false, allowUnboundThis: true }],
		'import/prefer-default-export': 0,
		'no-param-reassign': 0,
		'import/extensions': 0,
		'import/no-extraneous-dependencies': 0,
		'import/no-mutable-exports': 0,
		'import/no-duplicates': 0,
		'import-no-duplicates-prefix-resolved-path/no-duplicates': [
			'error',
			{
				prefixResolvedPathWithImportName: true,
			},
		],
	},
	ignorePatterns: [
		'**/*.js',
		'**/*.json',
		'node_modules',
		'public',
		'styles',
		'.next',
		'coverage',
		'dist',
		'.turbo',
	],
}
