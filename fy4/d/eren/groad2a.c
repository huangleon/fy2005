inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��ݵ�");
        set("long", @LONG
�߹����������де���ݵأ��ݺ��̣����룬�����ճ������޼����ݴ������
�Ƕ�ʢ���Ŵشص�Ұ�����߹����˱�����һ�󵭵��Ļ����У���ʱ���ᾪ��ֻ��
�죬һ��һ�ĵ���Զ��
LONG
        );
        set("exits", ([ 
	"southwest" : __DIR__"groad1",
	"northeast" : __DIR__"groad2",
	
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",30);
        set("coor/y",80);
        set("coor/z",0);
	set("map","eren");
	setup();

}


void dig_notify()
{
     	object me, worm,worm2;
     	    	
     	me = this_player();
     	if (me->is_busy()) {
     		tell_object(me,"��������æ��\n");
     		return;
     	}
     		
     	worm=present("yellow worm",this_object());
     	worm2=present("red worm",this_object());
     	
     	if(objectp(worm)|| objectp(worm2)) {
     		tell_object(me,"�����Ѿ��ڳ�һ������ˡ�\n");
     		return;
     	}
     	
     	message_vision("$N�ڵ������˿鳱ʪ�ĵط�����������\n", me);
     	if(query("already")>=5) {
     		tell_object(me,"�������򾶼�ڹ��ˡ�\n");
     		return;
     	}
     	
     	if (!random(5))	worm = new(__DIR__"obj/redworm");
        	else worm=new(__DIR__"obj/worm");
        worm->move(this_object());
        message_vision("$N�ӵ����ڳ�һ��"+worm->name()+NOR"��\n", me);
     	me->start_busy(2);
     	add("already",1);

}

void reset() {
	:: reset();
	set("already",0);
}


