
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����ںڰ������������ֲ�����ָ��Ψһ�Ĺ�������ǽ�Ϻ������������͵ơ�
���Ϻ�ǽ�ϲ����˰���ɫ��Ѫ�ۣ�ɢ�����������������ϴ����İ������������ĵ�
����ص�������ë����Ȼ�����ε��컨��������һ��ʯ�壬��ʯ��ķ�϶�������
�����⡣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		  "south" : __DIR__"dungeon",
	]));
        set("item_desc", ([
                "rock": "�ܳ��ص�ʯ�壬�����ƺ������ƶ�����\n",
		"ʯ��":"�ܳ��ص�ʯ�壬�����ƺ������ƶ�����\n"
        ]) );

	set("coor/x",0);
	set("coor/y",50);
	set("coor/z",5);
	setup();
}

void init()
{
        add_action("do_push", "push");
}

void check_trigger()
{
	object room;
        if( (int)query("trigger")==13 && !query("exits/up") ) {
                message("vision", "ʯ�����ڱ��Ƶ�б��������¶��һ�����ϵķ�϶��\n",this_object() );
                set("exits/up", __DIR__"east_castle");
        	if( room = find_object(__DIR__"east_castle") ) {
                	message("vision","���µ�ʯ�屻�Ƶ�б��������¶��һ��խ�졣\n",room );
                       room->set("exits/down", __FILE__);
        	}
                delete("trigger");
                call_out("close_passage", 5);
        }
}

void close_passage()
{
        object room;
        if( !query("exits/up") ) return;
        
        message("vision", "ʯ�塰�䡱��һ���ֵ��������������ϵ�ͨ����ס�ˡ�\n", this_object());
        if( room = find_object(__DIR__"east_castle") ) {
                message("vision", "ʯ�塰�䡱��һ���ֵ�����ȥ�������µ�ͨ����ס�ˡ�\n",room );
                room->delete("exits/down");
        }
	delete("exits/up");
	delete("trigger");
}


int do_push(string arg)
{
        string dir;

        if( !arg || arg=="" ) 
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }

        if( arg=="rock" || arg == "ʯ��") {
		if (query("exits/up")) {
			tell_object(this_player(),"ʯ���Ѿ����ƿ��ˡ�\n");
			return 1;
		}
		add("trigger", 1);
                write("���������������ƶ�ʯ�壬ʯ����Խ��Խ�ɶ���....\n");
		check_trigger();
                return 1;
                }
}


void reset()
{
        ::reset();
        delete("trigger");
}
 
