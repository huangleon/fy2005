// netbar.c

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;

	if (!arg)
		NETBAR_D->print();
	else if (arg == "-s") {
		NETBAR_D->netbar_switch();	
	}	
	else if (sscanf(arg, "-y + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("����ʹ���� *, +, ? ��β�ĵ�ַ��\n");
		else
			NETBAR_D->add(site);
	}
	else if (sscanf(arg, "-y - %s", site) == 1) {
		NETBAR_D->delete(site);
	}
	else if (sscanf(arg, "-n + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("����ʹ���� *, +, ? ��β�ĵ�ַ��\n");
		else
			NETBAR_D->add_ban(site);
	}
	else if (sscanf(arg, "-n - %s", site) == 1) {
		NETBAR_D->delete_ban(site);
	}
	else if (sscanf(arg, "-a + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("����ʹ���� *, +, ? ��β�ĵ�ַ��\n");
		else
			NETBAR_D->add_all(site);
	}
	else if (sscanf(arg, "-a - %s", site) == 1) {
		NETBAR_D->delete_all(site);
	}	
		
	else 
		write("��ο�ָ���ʽ	netbar -���� [+|- site]\n");

	return 1;
	
}

int help()
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ :		netbar -���� [+|- site] [0m
[0;1;37m����������������������������������������������������������������[0m   

����2005ȱʡ����Ϊÿ��ip��½�����˺š�
���������������������ÿ��ip�ĵ�½����

ʹ��˵��

netbar		����б�

netbar -s	���ز��������������Ƿ�����ip�ĵ�½����

netbar -y	+ xx.xx.xx.xx
netbar -y	- xx.xx.xx.xx
			��ĳ��ip��ip�μ���/����netbar����ip�����мӱ��ĵ�½��

netbar -n	+ xx.xx.xx.xx
netbar -n	- xx.xx.xx.xx
			��ĳ��ip��ip�μ���/����netbarn����ip��û�мӱ��ĵ�½��

Ϊʲô��netbar��netbarn�����أ�netbarn����������һ�ֺ�����
���������˵��������128.22.22.*�мӱ��ĵ�½�����ֲ�����
128.22.22.3�мӱ��ĵ�½����ô��Ӧ��ͬʱʹ����������
netbar -n + 128.22.22.3
netbar -y + 128.22.22


netbar -a + xx.xx.xx.xx		��ip�޵�½��������
netbar -a - xx.xx.xx.xx		�ָ�������״̬
ע�⣬�����������������ip����Ч��


�й����loginlock �ɸı�ÿ��ip�ĵ�½����

[0;1;37m����������������������������������������������������������������[0m 
HELP
	);
	return 1;
}