// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�ߵ���������䵱ɽ�����������������ƣ�������ˮ�������С����������ơ�
����ᡣ�ع������������쾡���������۽�ĺ�ƺϱڣ������޷���
LONG
	);
	set("exits", ([
        "eastup" : __DIR__"tianzhufeng",
	]));

	set("objects", ([
		__DIR__"npc/shui2" : 1,
   ]) );



	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",40);
	setup();
}

void reset()
{
    object shui, ob;
    
    shui = present("shui ruxi",this_object());
    if (shui)	
	{	if (!shui->query("real_shui"))	// fake SHUI
	    {
			if (!random(8))	{				
				shui->ccommand("sigh");
				message_vision(HIC"\n����ǰһ������������Ů���Ѳ�֪�Ӻδ��ճ�һ��ǳ��ɫ�Ķ̵���\n"NOR,shui);
				ob = new(__DIR__"npc/shui");
        		ob->move(this_object());
        		this_object()->set("boss_out",time());
        		destruct(shui);
        		return;
			}
		}
		else if (query("boss_out") + 3600 > time() || shui->is_fighting())
	    	return;
    	else {
    		shui->ccommand("sigh");
    		message_vision(CYN"ˮ�������е���һ��������δ������Ӱ�Ѳ�������þ���һ��΢�������\n"NOR,shui);
    		destruct(shui);
    		return;
    	}	
    }
    ::reset();
}

