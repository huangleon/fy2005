// imprison.c
#include "/doc/help.h"
#include <ansi.h>

#define SYNTAX	"ָ���ʽ��imprison <���id> because <ԭ��> for <����Сʱ>\n"
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	object room;
	string name,reason;
	int duration;
	
	if (!wizardp(me)) 
		return notify_fail("��û��Ȩ��ʹ�����ָ�\n");
	if (!arg) return notify_fail(SYNTAX);
	if (sscanf(arg, "%s because %s for %d", name, reason, duration)!=3)
		return notify_fail(SYNTAX);
		
	ob = find_player(name);
	if (!ob) return notify_fail("�Ҳ��������ҡ�\n");
	
	message_vision(HIR"\n$N��һ�ӣ�һ��΢�罫$n������Ƽ���������\n"NOR,me,ob);
	tell_object(ob,HIR"��Υ�����ƹ��򣬱���������" + duration + "Сʱ��\n\n"NOR);
	
	seteuid(geteuid(this_player(1)) );
	if(!(room =find_object(AREA_WIZ"jail")))
	room = load_object(AREA_WIZ"jail");
	ob->move(room);
	ob->set("imprison/start",time());
	ob->set("imprison/duration",60*60*duration);
	ob -> save();
	
	log_file("static/imprison", sprintf("[%s] %s imprison %s(%s) because %s for %d Сʱ.\n",
		ctime(time())[0..15], me->query("id"), ob->query("name"), ob->query("id"), reason, duration));	
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : imprison <���id> because <ԭ��> for <����Сʱ>[0m
[0;1;37m����������������������������������������������������������������[0m   

��ĳ����ҽ����ڷ��Ƶļ�����ڼ�����ʲôҲ�����ˣ�
һֱ��������������ߴ���ʱ��

[0;1;37m����������������������������������������������������������������[0m 
HELP
   );
   return 1;
}
