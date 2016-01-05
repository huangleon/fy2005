#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���幬��Ժ");
	set("long", @LONG
��ʯ���̳ɵĵ����ɨ�øɸɾ������������᷿����ʿ����ӵĵط���������
������Ʈ�������㡣Ժ�ڹ�ľ������գ���ǰ����һ������ɫ�Ĵ�����д��
[33m������[32m�������֡��ڳ����Ĵ������չ��š�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"da_dian",
  		"east" : __DIR__"kitchen",
  		"west" : __DIR__"xiang_fang",
	]));
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init()
{
    add_action("do_pull", ({"pull","open"}));
    if(query("exits/south")) {
	        set("item_desc", ([
	                "door": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
	                "��": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
	        ]) );
	}
	else {
	        set("item_desc", ([
	                "door": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull/open)�š�\n",
	                "��": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull/open)�š�\n",
	        ]) );      	
	}
}

int do_pull(string arg)
{
        object room, me;

        if( arg=="door" || arg == "��") {
                me = this_player();
                if(query("exits/south")) {
                        write("���ǿ��ŵģ�\n");
		}
		else {
                set("exits/south", __DIR__"taoguan");
	        set("item_desc", ([
	       	         "door": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
	       	         "��": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
       		 ]) );
                message_vision("$N�򿪴��š�\n", me);
                if( room = find_object(__DIR__"taoguan") ) {
                        message("vision", "���Ŵ�������˿�����\n", room);
	                room->set("exits/north", __FILE__);
			call_out("closedoor", 5, room);
                }
		}
	}
	else {
                 write("��Ҫ��ʲô��\n");
	}
	return 1;
}

int closedoor(object room)
{
	message("vision", "�����ֱ������ˡ�\n", room);
	message("vision", "�����ֱ������ˡ�\n", this_object());
        set("item_desc", ([
                "door": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
                "��": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
        ]) );
	room->delete("exits/north");
	delete("exits/south");
}
