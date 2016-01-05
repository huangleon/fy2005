#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���幬");
	set("long", @LONG
����ͭ�����Ž������ţ��ŵ��Ϸ�����һ����ң��������ɷ����д�ţ�����
�����������֡��ŵ��������һ��ͭʨ��ʹ�˸е�ׯ�ϵ���������������ط���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"south" : __DIR__"grassland2",
]));
        set("item_desc", ([
                "door": "ͭ���Ĵ��ţ��������Ż����������(knock)�š�\n",
                "��": "ͭ���Ĵ��ţ��������Ż����������(knock)�š�\n",
        ]) );
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}

void init()
{
//    	add_action("do_break", "break");
       	add_action("do_knock", "knock");
}

void wantopen(object me)
{
	object	waiter, tao1, tao2, tao3;
	object	room;


	seteuid(geteuid());
	room = find_object(__DIR__"da_yuan");

	message("vision", "\n֨��һ���������￪�ˡ�\n", this_object());
    if(present("taoist fighter", this_object())){
    	return;
    }
   	waiter = new(__DIR__"npc/waiter_taoist");
    message("vision", waiter->name()+ "���˹�����\n", this_object());
	if( room )  message("vision", waiter->name() + "֨��һ�����Ŵ򿪣����˳�ȥ��\n", room);
	waiter->move(this_object());
	message("vision", "������˵������λ"+ RANK_D->query_respect(me) + 
		"�����\n", this_object());
	call_out("closedoor", 10, me);
}

int do_knock(string arg)
{
	object room, me, thisroom;

        if( arg=="door" || arg == "��") {
		me = this_player();
		if(query("exits/north")) {
			message_vision(HIB "���ǿ��ŵģ���ʲô��\n"NOR, me);
			return 1;
		}
		message_vision(HIB "$N�ߵ���ǰ����������Ż��������¡�\n"NOR, me);
		set("long", @LONG
ͭ�����ų����ţ��ŵ��Ϸ�����һ����ң��������ɷ����д�ţ����幬��
�������֡��ŵ��������һ��ͭʨ��ʹ�˸е�ׯ�ϵ���������������ط���
LONG
	);
		set("exits/north", __DIR__"da_yuan");
	        if( room = find_object(__DIR__"da_yuan") ) {
			message("vision", HIB "�����������������������������š�\n"NOR, room);
			room->set("exits/south", __FILE__);
			room->set("item_desc", ([
                		"door": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
                		"��": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
        		]) );
		}
		me->start_busy(2);
		call_out("wantopen", 2, me);
		
        }
	else {
		write("��Ҫ��ʲô��\n");
	}
                return 1;
}

void closedoor(object me)
{
	object obj, room, troom;

	troom = this_object();
        
        room = find_object(__DIR__"da_yuan");			
		obj = present("fighter", troom);
		if(obj) {
			message("vision", obj->name() + "�߽����ۣ�����ذ��Ź����ˡ�\n", troom);
			destruct(obj); 
		}
		
		if(room) {
			room->delete("exits/south");
			room->set("item_desc", ([
               	"door": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
               	"��": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
        			]) );
			tell_room(room,"�����ֹ����ˡ�\n");
		}
		delete("exits/north");
		set("long", @LONG
����ͭ�����Ž������ţ��ŵ��Ϸ�����һ����ң��������ɷ����д�ţ���
�幬���������֡��ŵ��������һ��ͭʨ��ʹ�˸е�ׯ�ϵ���������������ط���
LONG
	);
		return;
}


void reset(){
	object room;
	::reset();
	if(query("exits/north")){
		set("long", @LONG
����ͭ�����Ž������ţ��ŵ��Ϸ�����һ����ң��������ɷ����д�ţ���
�幬���������֡��ŵ��������һ��ͭʨ��ʹ�˸е�ׯ�ϵ���������������ط���
LONG
		);	
		room = find_object(__DIR__"da_yuan");
		if(objectp(room) && room->query("exits/south")){
			room->delete("exits/south");
		}
		delete("exits/north");
	}
}
