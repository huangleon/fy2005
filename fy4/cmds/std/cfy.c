// emote.c (Mon  09-04-95)

#include <ansi.h>
inherit F_CLEAN_UP;
#define NEW_PERIOD 32400
int  check_legal_name(string name); 
int main(object me, string str)
{
    if (!str) {
        write(CYN"�㿴��������ḻ��\n"NOR);
        return 1;
    }
        if(me->query("chblk_on"))
                return notify_fail("���Ƶ�������ˣ�\n");
        if((int)me->query("mud_age") < NEW_PERIOD)
                return notify_fail("��ֻ����ʹ�ã�say����\n");
/*      str = replace_string(str, "$BLK$", BLK);
        str = replace_string(str, "$RED$", RED);
        str = replace_string(str, "$GRN$", GRN);
        str = replace_string(str, "$YEL$", YEL);
        str = replace_string(str, "$BLU$", BLU);
        str = replace_string(str, "$MAG$", MAG);
        str = replace_string(str, "$CYN$", CYN);
        str = replace_string(str, "$WHT$", WHT);
        str = replace_string(str, "$HIR$", HIR);
        str = replace_string(str, "$HIG$", HIG);
        str = replace_string(str, "$HIY$", HIY);
        str = replace_string(str, "$HIB$", HIB);
        str = replace_string(str, "$HIM$", HIM);
        str = replace_string(str, "$HIC$", HIC);
        str = replace_string(str, "$HIW$", HIW);
        str = replace_string(str, "$NOR$", NOR);*/
	if( strsrch(str, "$ME$") == -1 )
		str = "$ME$"+ str ;
//		write("��������ִ��б��躬��$ME$\n");
//	else{
	str = replace_string(str, "$ME$", me->name());
	if(check_legal_name(str))
	CHANNEL_D->do_channel(me, "fy", str,1);
//	}

    return 1;
}
 
int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	cfy <������>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ�����������һ��ϵͳû��Ԥ��Ķ�����, ϵͳ�Ὣ��������
�������е�$ME$�滻�������������ʾ�ڷ���Ƶ������û��$ME$��
��ϵͳ���Զ������������Ϣǰ���������֡�

������������ǰ���

��1����: cfy $ME$����������
��Ҿͻῴ��		[31m�����ơ���������������[0m

��2����: cfy ���ϵ��¸�$ME$����
��Ҿͻῴ��		[31m�����ơ����ϵ��¸���������[0m

���ָ��: semote, cemote

[0;1;37m����������������������������������������������������������������[0m   
HELP
	);
        return 1;
}

int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        while(i--) {
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ������������ġ�\n");
                        return 0;
                }
        }
	return 1;
}
