inherit ROOM;

void create()
{
        set("short", "��С��");
        set("long", @LONG
�����µı�����ǡ�˲���ɽ��һ��ɽ��С·������������ɽ�����죬���Ե�é
�ݸߴ���ߣ���ס����⣬ɽ���е�һ�ж��Ե���ɭ�İ���ż����������Ұ�޵�Х
�С������������Է�Ҳ��������é��(grass)�ƺ����ܸ����ˡ�
LONG
        );
        set("exits", ([ 
		  "south" : __DIR__"smallroad3",
		  "north" : __DIR__"sela",
]));
        set("objects", ([
                __DIR__"npc/woodcutter" :2,
        ]) );

        set("item_desc", ([
                "grass": "�����é��(grass)���ܣ������ƺ����Բ���(pushaside)���ǡ�\n",
                "é��": "�����é��(grass)���ܣ������ƺ����Բ���(pushaside)���ǡ�\n"

        ]) );

        set("outdoors", "resort");
	set("coor/x",40);
	set("coor/y",-30);
	set("coor/z",10);
	setup();
}

void init()
{
        add_action("do_push", "pushaside");
}

int do_push(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ����ʲô��\n");
                return 1;
        }
        if( arg == "grass" || arg == "é��" || arg == "��")
        {
	        me = this_player();
	        message_vision("$N����·�ߵ�é�ݣ�������һ��������·��\n", me);
		if( !query("exits/west") ) {
			set("exits/west", __DIR__"secret_road");
			call_out("close_path", 5);
		}
	        return 1;
        }
        else
        {
                write("��Ҫ����ʲô��\n");
                return 1;
        }
}


void close_path()
{
        if( !query("exits/west") ) return;
        message("vision","һ��紵����é�ݻ��˻Σ�����û��������·��\n", this_object() );
	delete("exits/west");
}
