// ban.c

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;

	if (!arg)
		BAN_D->print();
	else if (sscanf(arg, "+ %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("���ܽ��� *, +, ? ��β�ĵ�ַ��\n");
		else
			BAN_D->add(site);
		}
	else if (sscanf(arg, "- %s", site) == 1)
		BAN_D->delete(site);
	else if (sscanf(arg, "-a + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("���ܼ����� *, +, ? ��β�ĵ�ַ��\n");
		else
			BAN_D->add_allow(site);	
	}
	else if (sscanf(arg, "-a - %s", site) == 1)
		BAN_D->delete_allow(site);
	else 
		write("ָ���ʽ��ban -���� [+|- site]\n");

	return 1;

}

int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ :		ban [-a] [+|-] site [0m
[0;1;37m����������������������������������������������������������������[0m   

����������������ֹ�������⵷�ҡ�

+	�ǽ�ֹ���˷���
-	��ɾ��ban���ĵ�ַ
-a	�Ǽ����������ĵ�ַ

��������� ban + 211.100��Ȼ��ban -a + 211.100.99.11
������ban��������211.100���Σ���������211.100.99.11���ip����

���Բ���?��*��ͨ���

�������	nuke
		
[0;1;37m����������������������������������������������������������������[0m   

HELP
	);
	return 1;
}
