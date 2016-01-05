inherit ROOM;

void create()
{
    set("short", "������");
	set("long", @LONG
����һ���þ�ʯ���ɵĴ��Σ����ʵ�Χǽ��һ��Χǽ�����ı�֮�ߣ���ʹ���
���ṦҲ��һԽ���롣���ɫ�Ĵ�ʯͷ����һ�����µĸо������������Ⱥ���ľ
�ţ������ѿ�������
LONG
	);
    	set("exits", ([ /* sizeof() == 3 */
       	"northwest" : __DIR__"street5",
//       "east" : __DIR__"dalao1",
    	]));
    	set("objects", ([
        	__DIR__"npc/yuzu" : 2,
    	]) );
    	set("item_desc", ([
    		"door" : "��ɫ�Ĵ����쳣�ĺ�ʵ��������\n",
    		"ľ��" : "��ɫ�Ĵ����쳣�ĺ�ʵ��������\n",
	
    	]));
    	set("outdoors", "jinan");
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init(){
	add_action("open_door", "open");
}

int open_door(string arg){
	object me, obj;
	
	me = this_player();
	if(arg == "door"){
		if(query("exits/east")){
			return notify_fail("���ǿ��ŵġ�\n");
		}
		if(!me->query_temp("̽��") && !me->query("vendetta_mark")){
			return notify_fail("�η����ǲ�Ҫ�Ҵ���Ϊ�\n");
		} else {
			if(load_object(__DIR__"dalao1")){
				tell_object(me,"�������ƿ��˳��صĴ��š�\n");
				set("exits/east", __DIR__"dalao1");
			}				
		}
	}
	return 1;
}

int valid_leave(object me, string dir){
	object obj;
	
	if(dir == "east" && (!me->query_temp("̽��") && !me->query("vendetta_mark"))) {
		if(obj=present("yu zu", this_object())) {
			return notify_fail("����ȵ�����վס���η��صز����Ҵ�����\n");
		} else {
			return notify_fail("�η����ǲ�Ҫ�Ҵ���Ϊ�\n");
		}
	}
	if(query("exits/east")){
		message_vision("����һ���������ֹ����ˡ�\n", me);
		delete("exits/east");
	}
//	me->delete_temp("̽��");
	return 1;
}
