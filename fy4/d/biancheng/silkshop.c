inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "���ׯ");
        set("long", @LONG
�´��ĵĳ��ׯ�����󣬵������ֵط����Ѿ��������Ǻ��������ˡ����߿��
��̨�϶�����һƥƥ���޵ĳ�С�һ�����ֳɵ��·����������������ȴ�Ե�û��
��ɵ����ӣ�ֻϣ�����ڣ������ڵ�����Ȼ�ǻ�ƣ��ڼ���ȴ���ϰ塣�󷿵���
�����ţ��������Ű�͸����������������������龰��
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"nstreet1",
		"south": __DIR__"road3",
		"north": __DIR__"silkshop2",
	]));
        set("objects", ([
        	__DIR__"npc/huoji":	1,
        	__DIR__"npc/pregnant_woman": 1,
	]) );
	set("coor/x",-20);
        set("coor/y",10);
        set("coor/z",0);
	set("map","zbwest");
	setup();
}


void reset(){
	string *cloth = ({ RED"�����"NOR,BLU"������"NOR, HIG"�̶���"NOR, YEL"�ƶ���"NOR, "�����"});
	int code;
	object woman,worn;
	
	code = random(5);
	if (woman= present("pregnant woman",this_object())) {
		worn = woman->query_temp("armor/cloth");
//		write (sprintf("%O\n",worn));
		if (worn) {
			woman->set("cloth_code",code);
			worn->set("name",cloth[code]);
//			write (sprintf("%O\n",worn));
		}
	}
	::reset();
}
	
	
	