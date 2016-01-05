inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
������һƬ���֡����������ɸߵ����ӣ���ס��ͷ������գ��ܲ�͸�⡣
��������һ����ֵ��������������������������ţ��㾪�ֵط��֣��Ѿ���
�������ӵ�������º������߳�ȥ�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
			"south" : __DIR__"bomboo2",
			"east"  : __DIR__"bomboo2",
			"north" : __DIR__"bomboo2",
			"west"  : __DIR__"bomboo2",
		]));
        set("item_desc", ([
                "����": "һƬ�����ƺ������ƿ���push����\n",
                "bamboo": "������������ҡ�ڣ����ƺ������ۣ�pick������������\n",
				"����": "������������ҡ�ڣ����ƺ������ۣ�pick������������\n",
       ]) );
        set("outdoors", "fengyun");
		set("coor/x",-20);
		set("coor/y",480);
		set("coor/z",0);
        setup();
//        replace_program(ROOM);
}

void init()
{
	add_action("do_push","push");
	add_action("do_pick","pick");
	add_action("do_listen","listen");
}



int do_listen(){
	tell_object(this_player(),"����������ȴֻ��������������к���Ҷ��ɳɳ����\n");
	return 1;
}


int do_pick(string arg)
{
	object bamboo;
	if ( !arg && arg != "bamboo" && arg != "����" )
		return notify_fail("��Ҫ��ʲô��\n");
	if((int) query("picked") <= 3)
	{
		write("������һ����������ӣ�С�ĵķ��ڻ��\n");
		bamboo = new("/d/taoyuan/obj/bamboo");
		bamboo->move(this_player());
		add("picked",1);
		return 1;
	}
	else
        write("�����Ѿ������۹��ˣ���\n");
        return 1;
}

int do_push(string arg)
{
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "bamboo" || arg == "����" || arg == "����")
        {
	        me = this_player();
	        message_vision("$N�������ƿ����ӡ�\n", me);
	        me->start_busy(1);
		    if( !query("exits/southwest") ) {
	        	message_vision("�������ȥ��¶��һ��ͨ�����Ϸ����С����\n",me);
	        	set("exits/southwest", __DIR__"bomboo1");
    	    	call_out("close_path", 10);
        	}
        	return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}


void close_path()
{
        if( !query("exits/southwest") ) return;
        message("vision","���ӵ��˻�������ס��ȥ·��\n",this_object() );
        delete("exits/southwest");
}

