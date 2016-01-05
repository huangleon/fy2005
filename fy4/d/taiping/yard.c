inherit ROOM;
void create()
{
        set("short", "����СԺ");
        set("long", @LONG
��������һ��СԺ��������֦��չ��Ů������Ժǽ���������֣�֬�۵���ζ޹
���˻���������������һ�ֽ���ס�ĳ嶯����ӭ��һ������С¥������Ҷ�����
�ĸ������������ɷ��衣���ﴫ�����˿�񣬼��Ų�ȭ���������ۺ���֮�����ò�
���֡�����һ�������ι�����д�����԰���ź󼸸˴���̽��ͷ����
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"corridor1",
		"west": __DIR__"redhouse",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("coor/x",-70);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

void init()
{
     	add_action("do_pull", "pull");
        if(query("exits/east")) {
	        set("item_desc", ([
	                "door": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
	                "��": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
	        ]) );
	}
	else {
	        set("item_desc", ([
	                "door": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
	                "��": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
	        ]) );
	}
}

int do_pull(string arg)
{
        object room, me;
        if( arg=="door" || arg == "��" || arg == "����") {
                me = this_player();
                if(query("exits/east")) {
                        write("���ǿ��ŵģ�\n");
		}
		else {
	                set("exits/east", __DIR__"sroad1");
		        set("item_desc", ([
	       	         "door": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
	       	         "��": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
	       		 ]) );
                	message_vision("$N�򿪺��š�\n", me);
                	if( room = find_object(__DIR__"sroad1") ) {
	                        message("vision", "���Ŵ�������˿�����\n", room);
		                room->set("exits/west", __FILE__);
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
	room->delete("exits/west");
	delete("exits/east");
}