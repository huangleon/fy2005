#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���ﾡͷ");
        set("long", @LONG
С�ﲻ������ͷ��һ�Ⱥ��ţ����ź���һ������¥������̫ƽ��ģ�û�в�֪
�����Ⱥ��źͺ��ź�Ĺ���ġ�ԶԶ�������������٣������������ﻨ����ƽ����
��������߳�����¥�������û���˺�ڹ���С�����׻���һ������С¥��¥��
�ĺ��Ž����ع��š�
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"sroad2",
//		"west" : __DIR__"yard",
//		"south": __DIR__"songhouse",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        "door": "һ�Ⱥ��ţ�һ�Ⱥ��š�\n",
	        "����" : "�ʺ���ţ�����Ѫ�������������¥��\n",
        	"red door" : "�ʺ���ţ�����Ѫ�������������¥��\n",
        	"����": "��ڵ��ţ���������ȫ�����������ֺ�ɫ����һ������ɫ���Ѳ����˼����С���
�ϵ������ֻ��ƣ���Ȼ���ú������ȴ�Կ���������ʲô��������˵���������
�Ļ���ֻ��������ĳ�����ԵĲ�����а��\n",
		"black door": "��ڵ��ţ���������ȫ�����������ֺ�ɫ����һ������ɫ���Ѳ����˼����С���
�ϵ������ֻ��ƣ���Ȼ���ú������ȴ�Կ���������ʲô��������˵���������
�Ļ���ֻ��������ĳ�����ԵĲ�����а��\n",
	]));
	set("coor/x",-60);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

void init()
{
       	add_action("do_knock", "knock");
        add_action("do_open", "open");
        add_action("do_push", "push");
        if(query("exits/south")) {
	        set("item_desc", ([
	               	"door": "һ�Ⱥ��ţ�һ�Ⱥ��š�\n",
		        "����" : "�ʺ���ţ�����Ѫ�������������¥��\n",
	        	"red door" : "�ʺ���ţ�����Ѫ�������������¥��\n",
	                "black door": "��ڵ��ţ���������ȫ���������ſ��š�\n",
	                "����": "��ڵ��ţ���������ȫ���������ſ��š�\n",
	        ]) );
	}
	else {
	        set("item_desc", ([
        	"door": "һ�Ⱥ��ţ�һ�Ⱥ��š�\n",
	        "����" : "�ʺ���ţ�����Ѫ�������������¥��\n",
        	"red door" : "�ʺ���ţ�����Ѫ�������������¥��\n",
        	"����": "��ڵ��ţ���������ȫ�����������ֺ�ɫ����һ������ɫ���Ѳ����˼����С���
�ϵ������ֻ��ƣ���Ȼ���ú������ȴ�Կ���������ʲô��������˵���������
�Ļ���ֻ��������ĳ�����ԵĲ�����а��\n",
		"black door": "��ڵ��ţ���������ȫ�����������ֺ�ɫ����һ������ɫ���Ѳ����˼����С���
�ϵ������ֻ��ƣ���Ȼ���ú������ȴ�Կ���������ʲô��������˵���������
�Ļ���ֻ��������ĳ�����ԵĲ�����а��\n",
	        ]) );
	}
	
}


int do_open(string arg)
{
	if (arg=="door" || arg == "��" || arg=="black door" || arg == "����"
		|| arg=="red door" || arg == "����") {
			tell_object(this_player(),WHT "�Ź��ţ�Ҳ�����������һ�ơ�\n"NOR);
			return 1;
		}	
	return 0;
}

int do_knock(string arg)
{
	object room, me, thisroom;
	
	me = this_player();
        if( arg=="door" || arg == "��") {
	 	tell_object(me,"��Ҫ����һ���ţ�\n");
	 	return 1;
	}
	if (arg=="black door" || arg == "����") {
		if(query("exits/south")) {
			tell_object(me,HIB "���ǿ��ŵģ���ʲô��\n"NOR);
			return 1;
		}
		message_vision(HIB"$N�ߵ���ǰ����������Ż��������¡�\n"NOR,me);
		message_vision(HIB"������һ�㶯��Ҳû�С�\n"NOR,me);
		return 1;
	}
	if (arg=="red door" || arg == "����"){
		if(query("exits/west")) {
			tell_object(me,WHT "���ǿ��ŵģ���ʲô��\n"NOR);
			return 1;
		}
		message_vision(RED "$N�ߵ�����ǰ����������Ż��������¡�\n"NOR, me);
		set("exits/west", __DIR__"yard");
	        room = find_object(__DIR__"yard");
	        if (!room) room=load_object(__DIR__"yard");
	        message("vision", RED"�����������������������������š�\n"NOR, room);
		room->set("exits/east", __DIR__"sroad1");
		me->start_busy(2);
		call_out("wantopen", 1, me);
		return 1;	
        }
	tell_object(me, "��Ҫ��ʲô��\n");
	return 1;
}

void wantopen(object me)
{
	object	girl;
	object	room;

	seteuid(geteuid());
	room = find_object(__DIR__"yard");
	message("vision", "\n֨��һ��������������ˡ�\n", this_object());
    	if(present("redgirl", this_object())){
    		return;
    	}
   	girl = new(__DIR__"npc/redgirl");
    	message("vision", girl->name()+ "���˹�����\n", this_object());
	if(room)  
		message("vision", girl->name() + "֨��һ�����Ŵ򿪣����˳�ȥ��\n", room);
	girl->move(this_object());
	message("vision", girl->name()+"˵������λ"+ RANK_D->query_respect(me) + 
		"�����\n", this_object());
	call_out("closedoor", 10, me);
}


void closedoor(object me)
{
	object obj, room, troom;

	troom = this_object();
	if(me && environment(me) != troom) {
	    room = find_object(__DIR__"yard");
		obj = present("redgirl", troom);
		if(obj) {
			message("vision", obj->name() + "�߽����ţ�����ذ��Ź����ˡ�\n", troom);
			destruct(obj); 
		}
		if(room) {
			room->delete("exits/east");
			room->set("item_desc", ([
                	"door": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
                	"��": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
        		]) );
			message("vision", RED"�����ֱ������ˡ�\n"NOR, room);
			delete("exits/west");
		}
	} else {
		call_out("closedoor", 15, me);
	}
}

int do_push(string arg)
{
        object room, me;
        me=this_player();
        
        if(arg == "��" || arg =="door" ) {
        	tell_object(me,"��Ҫ����һ���ţ�\n");
        	return 1;
        }
        if( arg=="red door"|| arg == "����") {
        	if(query("exits/west")) {
			tell_object(me,RED "���ǿ��ŵģ���ʲô��\n"NOR);
			return 1;
		}
        	
        	tell_object(me,"�����������ƣ�������˿������\n");
        	return 1;
        }
        if( arg=="black door" || arg == "����") {
                me = this_player();
                if(query("exits/south")) {
                        write("�����ǿ��ŵģ�\n");
		}
		else {
	                set("exits/south", __DIR__"songhouse");
		        set("item_desc", ([
	                "door": "һ�Ⱥ��ţ�һ�Ⱥ��š�\n",
	        	"����" : "�ʺ���ţ�����Ѫ�������������¥��\n",
        		"red door" : "�ʺ���ţ�����Ѫ�������������¥��\n",
	                "black door": "��ڵ��ţ���������ȫ���������ſ��š�\n",
	                "����": "��ڵ��ţ���������ȫ���������ſ��š�\n",
	       		 ]) );
                	message_vision("$N����һ�ƣ�����֨ѽһ�����ˡ�\n", me);
                	if( room = find_object(__DIR__"songhouse") ) {
	                        message("vision", "���ű��˴������ƿ��ˡ�\n", room);
		                room->set("exits/north", __FILE__);
				call_out("closebdoor", 5, room);
                	}
		}
	}
	else {
                 write("��Ҫ��ʲô��\n");
	}
	return 1;
}



int closebdoor(object room)
{
	message("vision", "�����ֱ������ˡ�\n", room);
	message("vision", "�����ֱ������ˡ�\n", this_object());
        set("item_desc", ([
        	"door": "һ�Ⱥ��ţ�һ�Ⱥ��š�\n",
	        "����" : "�ʺ���ţ�����Ѫ�������������¥��\n",
        	"red door" : "�ʺ���ţ�����Ѫ�������������¥��\n",
        	"����": "��ڵ��ţ���������ȫ�����������ֺ�ɫ����һ������ɫ���Ѳ����˼����С���
�ϵ������ֻ��ƣ���Ȼ���ú������ȴ�Կ���������ʲô��������˵���������
�Ļ���ֻ��������ĳ�����ԵĲ�����а��\n",
		"black door": "��ڵ��ţ���������ȫ�����������ֺ�ɫ����һ������ɫ���Ѳ����˼����С���
�ϵ������ֻ��ƣ���Ȼ���ú������ȴ�Կ���������ʲô��������˵���������
�Ļ���ֻ��������ĳ�����ԵĲ�����а��\n",
        ]) );
	room->delete("exits/north");
	room->set("item_desc", ([
               	"door": "��ɫ��ľ���ţ����ǹ��ŵģ��������(pull)�š�\n",
               	"��": "��ɫ��ľ���ţ����ǹ��ŵģ��������(pull)�š�\n",
        ]) );
	delete("exits/south");
}


void reset(){
	object room;
	::reset();
	if(query("exits/west")){
		room = find_object(__DIR__"yard");
		if(objectp(room) && room->query("exits/east")){
			room->delete("exits/east");
		}
		delete("exits/west");
	}
	if(query("exits/south")){
		room = find_object(__DIR__"songhouse");
		if(objectp(room) && room->query("exits/north")){
			room->delete("exits/north");
		}
		delete("exits/south");
	}
}