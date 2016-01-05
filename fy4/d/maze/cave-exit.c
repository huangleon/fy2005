// silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������������һ���ط���Ȼ����һ��С�ݣ�����˵�����ӣ�������˵��ʯ�� 
��һ����Ȼ�����ĵط���Լ�����ɼ�������ʪ�ĵ��Ͼ����䶯����Ѫ����ȱ��ʬ�� 
�Ͳ�֪���Ĳ�ҩ��������������һ��������Ż�Ķ�������Ӻ�ͨ��һ��һ�ɼ���
�ĳ��ӣ�������ɫ��Һ�壬����ð��Ѫ��֮���� 
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"north" : __DIR__"cave-maze/exit",
		"south" : __DIR__"cave-end",

	]));
        set("item_desc", ([
        	"����":	"ԶԶ��ȥ�������ﾡ����ɫ��Һ�壬����ð��Ѫ��֮���� \n",
        	"pond":	"ԶԶ��ȥ�������ﾡ����ɫ��Һ�壬����ð��Ѫ��֮���� \n",
		"south":"ԶԶ��ȥ�������ﾡ����ɫ��Һ�壬����ð��Ѫ��֮���� \n",
	]) );
	setup();
	
}


int	valid_leave(object who, string dir){
	object room, y1, y2, y3, y4;
	
	if (dir == "south") {
		if (REWARD_D->riddle_check(who,"�ǻ�Ѫ��")!=2)
			return notify_fail(BLU"��ֻ�����������棬�������֮��������ͣס�˽Ų���\n"NOR);
		room = find_object(__DIR__"cave-end");
		if (room->usr_in()) 
			return notify_fail("��Ѩ��С���ƺ��Ѿ������������ˡ�\n");		
		message_vision(BLU"
ͻȻ�����������Ĺ�Ũ�̣��û����ĸ�������ҹ�档 \n\n"
HIR"ҹ���Ĵ�һ�������������󵨿�ͽ��˽���񶴣��������ɣ� \n\n"NOR,who);
		room->reset();		
	}
		
	return 1;
}	