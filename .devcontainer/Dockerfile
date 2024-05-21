FROM docker.io/debian

# Setup apt for github-cli
RUN mkdir -p -m 755 /etc/apt/keyrings
RUN wget -qO- https://cli.github.com/packages/githubcli-archive-keyring.gpg > /etc/apt/keyrings/githubcli-archive-keyring.gpg 
RUN chmod go+r /etc/apt/keyrings/githubcli-archive-keyring.gpg
RUN echo -n 'deb [signed-by=/etc/apt/keyrings/githubcli-archive-keyring.gpg] ' >> /etc/apt/sources.list.d/github-cli.list
RUN echo -n 'https://cli.github.com/packages stable main' >> /etc/apt/sources.list.d/github-cli.list

# Install gh
RUN apt-get update
RUN apt-get install -y gh build-essential
