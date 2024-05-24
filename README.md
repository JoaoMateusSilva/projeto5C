# projeto5C
<h3>projeto 5 da aula de algoritmo escrito em C</h3>

<h4>Heron de Souza 22.223.009-6</h4>
<h4>João Mateus E B da Silva 22.223.013-8</h4>
<h4>Rafael Denis Alonso 22.223.016-1</h4>

<h2>Descrição Geral</h2>
    <p>Este projeto é um sistema de gerenciamento de contatos desenvolvido em C. Ele permite adicionar, listar, deletar, salvar e carregar contatos a partir de arquivos binários. O sistema agora possui novas funcionalidades que aprimoram a usabilidade e integridade dos dados.</p>

  <h2>Novas Funcionalidades</h2>
    <ul>
        <li><strong>Validação do Email</strong></li>
    </ul>
    <p>A validação do email garante que os endereços de email inseridos estejam no formato correto (ex.: nome@dominio.com). Isso ajuda a evitar erros de digitação e a garantir que os emails registrados sejam válidos.</p>

  <ul>
        <li><strong>Telefone Único</strong></li>
    </ul>
    <p>A nova funcionalidade de telefone único assegura que não existam dois contatos com o mesmo número de telefone. Isso evita duplicidade de dados e facilita a busca e gerenciamento dos contatos.</p>

  <ul>
        <li><strong>Opção de Alterar Dados do Contato</strong></li>
    </ul>
    <p>Agora é possível alterar os dados de um contato existente. Isso inclui modificar informações como nome, email e telefone, proporcionando maior flexibilidade na manutenção da lista de contatos.</p>

  <ul>
        <li><strong>Trabalhar com 2 Listas de Contatos</strong></li>
    </ul>
    <p>O sistema agora suporta duas listas de contatos separadas: uma para contatos pessoais e outra para contatos de trabalho. Cada lista pode armazenar até 255 contatos e utiliza espaços de memória separados. Isso permite uma organização mais clara e eficiente dos contatos, diferenciando entre contatos pessoais e profissionais.</p>

  <h2>Implementação</h2>
    <p>Para implementar essas novas funcionalidades, foram feitas as seguintes mudanças:</p>
    <ul>
        <li>A validação do email foi adicionada na função de criação e alteração de contatos.</li>
        <li>Foi adicionada uma verificação na função de criação e alteração de contatos para garantir que o número de telefone seja único.</li>
        <li>Uma nova função foi criada para permitir a alteração de dados dos contatos existentes.</li>
        <li>O sistema foi modificado para utilizar dois arrays distintos para armazenar os contatos pessoais e de trabalho, garantindo que a escolha da lista não seja armazenada dentro dos dados de cada contato.</li>
    </ul>

  <h2>Conclusão</h2>
    <p>Estas novas funcionalidades tornam o sistema de gerenciamento de contatos mais robusto e fácil de usar, garantindo a integridade dos dados e oferecendo uma melhor organização dos contatos pessoais e profissionais.</p>
    <h2> Como compilar e executar </h2>
<h4>Para compilar o programa em C, é necessário ter um compilador C instalado, como o GCC (GNU Compiler Collection) ou entrar em um ambiente de desenvolvimento integrado online, como exemplo, o Replit. Após isso, você pode compilar o programa da seguinte forma:</h4>

<ul>
        <li>Primeiro: abra o terminal.</li> 
        <li>Segundo: use o comando gcc -c main.c -o main.o e o comando gcc -c contatos.c -o contatos.o . </li> 
        <li>Terceiro: use o comando gcc main.o contatos.o -o exec. Onde "exec" é o nome que você deseja dar ao arquivo executável e main.c e contatos.c são os nomes dos arquivos desse programa.</li> 
        <li>Por fim: para executar o programa compilado basta digitar ./exec, no caso desse ser o nome do seu arquivo executável. </li> 
</ul>
