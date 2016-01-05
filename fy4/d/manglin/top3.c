// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ROOM;
mapping directions= ([
		"west":		"����",
		"north":	"����",
		"east":		"����",
		"south":	"�Ϸ�"
			]);
			
void echoforest(object me);
void create()
{
        set("short", "������");
        set("long", @LONG
������������ȥ���ֺ�ãã�����ޱ߼ʡ�Ũ�ܵ���֦��һ���ʵ�ĵ�̺�̸���
������أ�������һ���·�ĺۼ���������ϴ�׳��[37m��֦[32m������������չ��������
һ����Ϊ�⻬���ƺ��Ǿ��������ʰѹ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"center3",

]));
        set("outdoors", "manglin");
	set("current_dir",0);
	set("coor/x",100);
	set("coor/y",0);
	set("coor/z",50);
	setup();
}

void init()
{
add_action("do_swing","swing");
add_action("do_turn","turn");
add_action("do_look","look");
}
int do_look(string arg)			// EAST END
{
	if( arg == "vine" 
		|| arg == "��֦" )
	{
	write("��������������׳�⻬����֦����������˷�����������ŵ�������swing����
��������ȥ�ķ��������α��ܹ�������Ҫȥ�ĵط��ˡ�
������÷ɽׯ���ϣ��Ϻ������������򣩱������Ƴǣ�\n");
	return 1;
	}
	return 0;
}

int do_swing(string arg)		// EAST END
{
	object me;
	int c_dir;
	me = this_player();
   	
   	if (arg == "west" || arg == "north" || arg == "east" || arg == "south") {
   		 if (!random(10))	echoforest(me);
   		 message_vision("\n\n$Nץ����֦��������"+directions[arg]+"��ȥ��	
���Ŷ��ߵĺ���������$N�������е���
������������ŶŶŶŶŶŶ����������������\n\n",me);
		if(arg == "east")
			me->move(__DIR__"edge3");
		else
			switch (arg) {
				case "west":	me->move(__DIR__"top1"); break;
				case "north":	me->move(__DIR__"top2"); break;
				case "south":	me->move(__DIR__"top4"); break;
			}
		return 1;
	}

	tell_object(me,"����Ҫ��ʲô����swing east/south/west/north��\n");		
		
	return 1;

}


int do_turn(string arg)
{
	object me;
	int c_dir;
	me = this_player();
    if( arg == "vine" || arg == "��֦" )
    {
		message_vision("$N���ݺ��ݵ������⶯��֦���ֻ��������յ�����ʱ�⡣\n",me);
        return 1;
    }
        
    tell_object(me,"����ת��ʲô�����˴��ɡ�turn vine ���� turn ��֦����\n");   
    return 1;

}

void echoforest(object me)
{
int i;
object room;
string *names = ({"center1","center2","center3", "center4",
		"dummy1","dummy2","dummy3","dummy4",
		"groupe1","groupe2","groupe3","groupe4",
                "groupw1","groupw2","groupw3","groupw4",
                "groupn1","groupn2","groupn3","groupn4",
                "groups1","groups2","groups3","groups4",
		"top1","top2","top4" });
for(i=0;i<sizeof(names);i++)
{
if( room = find_object(__DIR__+names[i]))
tell_object(room,HIW "\n\nԶ������һ�����У���������������ŶŶŶŶŶŶ������������������\n\n"NOR);
}
}
void reset()
{

::reset();

	set("current_dir" , random(4));
}
