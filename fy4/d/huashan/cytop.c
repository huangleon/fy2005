// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "��������");
    set("long", @LONG
�嶥�����ߴ�����ɣ����ڷ嶥���˿���ɫ��̺�ӣ�����Ũ����գ�����ʯ��
�����������롣�޷��ʱ������ʯ���ϣ��������������������ѵ�������Ȼ��
��ɽ�紵���������ּ�ֻ���������󣬴���˷�������һ����ɫ��
LONG
    );
    set("exits", ([ 
	"down" : __DIR__"chaoyang",
      ]));
    set("objects", ([
	__DIR__"obj/pineneedle" : 1,
	__DIR__"obj/pinetree" : 1,
	"/obj/animal/songshu" : 1,
	__DIR__"npc/suu2" : 1,
      ]));  
    set("outdoors", "huashan");

    set("coor/x",-4);
    set("coor/y",-53);
    set("coor/z",123);
    setup();
}


void reset()
{
    object shui, ob;
    
    shui = present("suu xiaoxiao",this_object());
    if (shui)	
	{	if (!shui->query("real_suu"))	// fake SHUI
	    {
			if (!random(8))	{				
				shui->ccommand("sigh");
				message_vision(HIG"\n��С����������һ˫��ָ�ף�̧��ͷ��������һЦ�����ǲ��ǣ��Ѿ������Һܾ��ˣ�\n\n"NOR,shui);	
				ob = new(__DIR__"npc/suu");
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
    		message_vision("$N�����߽�ɽ������ʧ�ˡ�\n",shui);
    		destruct(shui);
    		return;
    	}	
    }
    ::reset();
}

