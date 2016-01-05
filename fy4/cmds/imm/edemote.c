// edemote.c
#include <ansi.h>
inherit F_CLEAN_UP;

int in_use;

int main(object me, string arg)
{
	mapping emote;

	if( !arg ) return notify_fail("��Ҫ�༭ʲ�� emote��\n");

	if( sscanf(arg, "-d %s", arg) ) {
		write("ɾ�� emote��" + arg + "\n");
		CHANNEL_D->delete_emote(arg);
		return 1;
	}

	if( sscanf(arg, "-p %s", arg) ) {
		emote = CHANNEL_D->query_emote(arg);
		printf("�ϴ��޸ģ�%s\n", emote["updated"]);
		printf("��������������������������\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
			emote["myself"], emote["others"], emote["myself_self"],
			emote["others_self"], emote["myself_target"], emote["target"],
			emote["others_target"] );
		return 1;
	}

	emote = CHANNEL_D->query_emote(arg);
	emote = (["updated":geteuid(me)]);

	write("�༭ emote��" + arg + "\n");
	write("ѶϢ�����кü��У��� . ��ʾ������\n");
	write("ѶϢ�п�ʹ�õĲ��������¼��֣�\n");
	write("  $N  �Լ������֡�\n");
	write("  $n  ʹ�ö�������֡�\n");
	write("  $P  �Լ����˳ƴ����ʣ����㡢�ҡ�����������������\n");
	write("  $p  ʹ�ö�����˳ƴ����ʣ����㡢�ҡ�����������������\n");

	write("������������������������������������������������������������������������\n");
	write("��ָ������ʹ����� emote ʱ�����Լ�������ѶϢ��\n->");
	input_to("get_msg_myself", emote, arg);
	return 1;
}

string getincolor(string emote)
{
      emote = replace_string(emote, "$BLK$", BLK);
      emote = replace_string(emote, "$RED$", RED);
      emote = replace_string(emote, "$GRN$", GRN);
      emote = replace_string(emote, "$YEL$", YEL);
      emote = replace_string(emote, "$BLU$", BLU);
      emote = replace_string(emote, "$MAG$", MAG);
      emote = replace_string(emote, "$CYN$", CYN);
      emote = replace_string(emote, "$WHT$", WHT);
      emote = replace_string(emote, "$HIR$", HIR);
      emote = replace_string(emote, "$HIG$", HIG);
      emote = replace_string(emote, "$HIY$", HIY);
      emote = replace_string(emote, "$HIB$", HIB);
      emote = replace_string(emote, "$HIM$", HIM);
      emote = replace_string(emote, "$HIC$", HIC);
      emote = replace_string(emote, "$HIW$", HIW);
      emote = replace_string(emote, "$NOR$", NOR);
	return emote;
}
int get_msg_myself(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["myself"]) )
		{
		emote["myself"] = getincolor(emote["myself"]);
		emote["myself"] += "\n";
		}
		write("��ָ������ʹ����� emote ʱ�������˿�����ѶϢ��\n->");
		input_to("get_msg_others", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["myself"]) )
		emote["myself"] += msg + "\n";
	else emote["myself"] = msg;
	write("->");
	input_to("get_msg_myself", emote, pattern);
	return 1;
}

int get_msg_others(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["others"]) )
                {
                emote["others"] = getincolor(emote["others"]);
                emote["others"] += "\n";
                }
		write("���Լ�ʹ����� emote ʱ���Լ�������ѶϢ��\n->");
		input_to("get_msg_myself_self", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["others"]) )
		emote["others"] += msg + "\n";
	else emote["others"] = msg;
	write("->");
	input_to("get_msg_others", emote, pattern);
	return 1;
}

int get_msg_myself_self(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["myself_self"]) )
                {
                emote["myself_self"] = getincolor(emote["myself_self"]);
                emote["myself_self"] += "\n";
                }
		write("���Լ�ʹ����� emote ʱ�������˿�����ѶϢ��\n->");
		input_to("get_msg_others_self", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["myself_self"]) )
		emote["myself_self"] += msg + "\n";
	else emote["myself_self"] = msg;
	write("->");
	input_to("get_msg_myself_self", emote, pattern);
	return 1;
}

int get_msg_others_self(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["others_self"]) )
                {
                emote["others_self"] = getincolor(emote["others_self"]);
                emote["others_self"] += "\n";
                }
		write("�Ա���ʹ����� emote ʱ���Լ�������ѶϢ��\n->");
		input_to("get_msg_myself_target", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["others_self"]) )
		emote["others_self"] += msg + "\n";
	else emote["others_self"] = msg;
	write("->");
	input_to("get_msg_others_self", emote, pattern);
	return 1;
}

int get_msg_myself_target(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["myself_target"]) )
                {
                emote["myself_target"] = getincolor(emote["myself_target"]);
                emote["myself_target"] += "\n";
                }
		write("�Ա���ʹ����� emote ʱ��ʹ�ö��󿴵���ѶϢ��\n->");
		input_to("get_msg_target", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["myself_target"]) )
		emote["myself_target"] += msg + "\n";
	else emote["myself_target"] = msg;
	write("->");
	input_to("get_msg_myself_target", emote, pattern);
	return 1;
}

int get_msg_target(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["target"]) )
                {
                emote["target"] = getincolor(emote["target"]);
                emote["target"] += "\n";
                }
		write("�Ա���ʹ����� emote ʱ�������Լ���ʹ�ö����⣬�����˿�����ѶϢ��\n->");
		input_to("get_msg_others_target", emote, pattern);
		return 1;
	}
	if( !undefinedp(emote["target"]) )
		emote["target"] += msg + "\n";
	else emote["target"] = msg;
	write("->");
	input_to("get_msg_target", emote, pattern);
	return 1;
}

int get_msg_others_target(string msg, mapping emote, string pattern)
{
	if (msg==".") {
		if( !undefinedp(emote["others_target"]) )
                {
                emote["others_target"] = getincolor(emote["others_target"]);
                emote["others_target"] += "\n";
                }
		CHANNEL_D->set_emote(pattern, emote);
		write("Emote �༭������\n");
		return 1;
	}
	if( !undefinedp(emote["others_target"]) )
		emote["others_target"] += msg + "\n";
	else emote["others_target"] = msg;
	write("->");
	input_to("get_msg_others_target", emote, pattern);
	return 1;
}

int help(object me)
{
write(@HELP

[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	edemote [-d|-p] <emote>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ������޸�, ɾ�� emote ���г�������. ���� -d ������ɾ��
ָ���� emote, -p ��������г�ָ�� emote ������. �г���˳�����
�� emote ʱ��ͬ.

���� emote ѶϢʱ��������Ŀ: û��Ŀ��, ָ��Ŀ����Ƕ��Լ�. ��
������ĳ��ѶϢ, ��ֱ���ڿհ������� '.' ����.

һ�� emote ѶϢ�����кܶ���, �ڿհ������� '.' ����������� emote.

�༭ emote ʱ���������µķ�������ʾ:

$N : �Լ�������.
$n : Ŀ�������.
$P : �Լ����˳ƴ�����.
$p : Ŀ����˳ƴ�����.
$S : ���Լ��ĳƺ���
$s : ���Լ��Ĵ�³�ƺ���
$C : ���Լ����سơ�
$c : �Ա��˵��سơ�
$R : �Ա��˵���ơ�
$r : �Ա��˵Ĵ�³�ƺ���

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
