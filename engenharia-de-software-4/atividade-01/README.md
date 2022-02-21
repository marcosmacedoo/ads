# Atividade 01

- Criando um o arquivo `helloWorld.js`
```bash
marcos in ads/engenharia-de-software-4/atividade-01 on  main [?] 
❯ touch helloWorld.js
```

- No arquivo `helloWorld.js` iremos adicionar um código
```javascript
console.log('Hello World')
```

- Adicionando `helloWorld.js` a staged
```bash
marcos in ads/engenharia-de-software-4 on  main [!+] 
❯ git add atividade-01/helloWorld.js 
marcos in ads/engenharia-de-software-4 on  main [!+] 
❯ git status                        
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
	new file:   atividade-01/README.md
	new file:   atividade-01/helloWorld.js

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
	modified:   atividade-01/README.md
```

- Commitando o `helloWorld.js`
``` bash
marcos in ads/engenharia-de-software-4 on  main [!+] 
❯ git commit -m "initial commit"                     
[main 3ceea45] initial commit
 2 files changed, 8 insertions(+)
 create mode 100644 engenharia-de-software-4/atividade-01/README.md
 create mode 100644 engenharia-de-software-4/atividade-01/helloWorld.js
```

- Voltando um commit
```bash
marcos in ads/engenharia-de-software-4 on  main [⇡!] took 11s 
❯ git reset --hard                                         
HEAD is now at 3ceea45 initial commit
```

- Removendo um arquivo da area de staged
```bash
marcos in ads/engenharia-de-software-4 on  main [⇡!] 
❯ git restore atividade-01/README.md
```