![Electron Scaffolder](./logo.png)

Electron Scaffolder is a CLI that generates an Electron starter application & scaffolds a project with Typescript, ReactJS & WebpackJS with enough configuration to get you started on your next exciting Electron project!

![Electron Scaffolder Libraries](./libs.png)

⚠️⚠️⚠️ Currently Electron Scaffolder only works on Linux / Mac OS. We are currently working on Windows compatibility...

## Getting started

### Install
```
npm install -g electron-scaffolder
```

### Create & Run Your Project
```
electron-scaffolder my_project
cd my_project
npm run start
```

Electron Scaffolder will generate your project for you with the below file structure tree:
```
├── README.md
├── index.html
├── main.js
├── package-lock.json
├── package.json
├── src
│   ├── index.tsx
│   ├── sass
│   │   └── index.scss
│   └── views
│       ├── index.ts
│       ├── main.styles.tsx
│       └── main.tsx
├── tsconfig.json
└── webpack.config.js
```

### List all commands
```
electron-scaffolder --help
```