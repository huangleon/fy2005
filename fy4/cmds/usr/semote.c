// semote.c
#include "/doc/help.h" 
inherit F_CLEAN_UP; 
int main(object me, string arg)
{
    string *e;
    string verbs;
    int i; 
    object ob;
    ob = this_player();
    if (ob->query_temp("timer/semote")+2 > time())
	return notify_fail("���һ�����ʹ�ã������塣\n");
    ob->set_temp("timer/semote",time());
    //e = sort_array(EMOTE_D->query_all_emote(), 1);
    if (!arg)
    {
	e = sort_array(EMOTE_D->query_all_emote(), 1);
    }else
    {
	arg = replace_string(arg, "$","");
	arg = replace_string(arg, "N","");
	arg = replace_string(arg, "P","");
	arg = replace_string(arg, "n","");
	arg = replace_string(arg, "p",""); 
	verbs = CHANNEL_D->search_emote(arg);
	if (strlen(verbs) > 0)
	{
	    e = explode(verbs,"+");
	}else
	{
	    write("No Match Found!\n");
	    return 1;
	} 
    }  
    for(i=0; i<sizeof(e); i++)
	printf("%-15s%s", e[i], (i%5==4)?"\n": "");
    write("\n");
    return 1;
} 
int help(object me)
{
    write(@HELP
ָ���ʽ : semote [�����ַ���] 
���ָ������г�Ŀǰ����ʹ�õ�emote.
�����Ҫ�ҵ������ض��ַ�����emote,
ʹ�� semote ��������ҵ��ַ�����
HELP
    );
    return 1;
}
