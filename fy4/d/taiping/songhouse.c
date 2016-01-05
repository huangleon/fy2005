// seaside.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
ǽ������ڣ������������ڵ�һƬ���Ŵ��ĺ���ǣ�źڲ����������δ��춼��
��ڣ������ط��·�͹��������İ�Ӱ�С����ŵ�ǽ��֮ǰ����һ����̳��������
��ڵ���ᣣ�Ҳ��֪̳�Ϲ��ŵ���ʲô��̳ǰ��һ��������������������ڶ���һ
�����衣����������֮�䣬�����ںڵ�һ���Բ����
LONG
        );
        set("exits", ([ 
		"south": __DIR__"songhouse2",
		"up": __DIR__"songhouse3",
	]));
        set("objects", ([
        	__DIR__"npc/song": 1,
        	__DIR__"obj/altar": 1,
        	__DIR__"obj/altar2": 1,
        ]));
        set("item_desc", ([
	
	 ]));
	set("coor/x",-60);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

void init()
{
        if(query("exits/north")) {
	        set("item_desc", ([
	                "door": "��ɫ��ľ���ţ����ǿ��ŵġ�\n",
	                "��": "��ɫ��ľ���ţ����ǿ��ŵġ�\n",
	        ]) );
	}
	else {
	        set("item_desc", ([
	                "door": "��ɫ��ľ���Ž����ع��ţ��������(pull)�š�\n",
	                "��": "��ɫ��ľ���Ž����ع��ţ��������(pull)�š�\n",
	        ]) );
	}
	add_action("do_pull", "pull");
}

int do_pull(string arg)
{
        object room, me;
        if( arg=="door" || arg == "��" || arg == "����") {
                me = this_player();
                if(query("exits/north")) {
                        write("�����ǿ��ŵģ�\n");
		}
		else {
	                set("exits/north", __DIR__"sroad1");
		        set("item_desc", ([
		       	         "door": "��ɫ��ľ���ţ����ǿ��ŵġ�\n",
		                "��": "��ɫ��ľ���ţ����ǿ��ŵġ�\n",
	       		 ]) );
                	message_vision("$N�����������š�\n", me);
                	if( room = find_object(__DIR__"sroad1") ) {
	                        message("vision", "���Ŵ�������˿�����\n", room);
		                room->set("exits/south", __DIR__"songhouse");
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
                "door": "��ɫ��ľ���Ž����ع��ţ��������(pull)�š�\n",
	        "��": "��ɫ��ľ���Ž����ع��ţ��������(pull)�š�\n",
        ]) );
	room->delete("exits/south");
	delete("exits/north");
}

int valid_leave(object me,string dir)
{
	object ob;
	if(userp(me) && dir == "up" && ob=present("mother song",this_object()))
	{
		if (me->query("family/master_id")!="master yin"){
			message_vision(ob->name()+"˵����̫�ŵ�¥���ҵúܣ����˻���ֹ���ɡ�\n",me);
			return notify_fail("");
		}
		else {
			message_vision(ob->name()+"˵����̫�ŵ�¥���ҵúܣ���������үִ��Ҫ�������ϰɡ�\n",me);
			return 1;
		}
	}
	return 1;
}

void reset()
{
	object *inv;
        object item1,table;
        int i,needle;
        
        ::reset();
        table = present("jizhuo", this_object());
        if (table) {
	        inv = all_inventory(table);
	        for (i=0;i<sizeof(inv);i++) {
	        	if (inv[i]->query("name")=="��ɫ��Բ��") needle=1;
	        }
	        if (!needle) {
	        	item1 = new(__DIR__"obj/blackpie");
	        	item1->move(table);
	        	}
	}
}