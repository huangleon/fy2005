inherit ROOM;

void create()
{
        set("short", "�Ͼ�");
        set("long", @LONG
Ӫ��������һ�������ľ��ܣ�������ˮͰ���ҵص����ڵ��ϡ����¿�ȥ���ڹ�
¡�˵ز����ף�����һ��ʯ�ӣ���������ž��׹�����ھ��ڻ��죬ԭ���Ѿ��ɿ���
��֪�����ꡣ������˩��һƥû����ɵ�����
LONG
        );
        set("exits", ([ 
	  	"east" : __DIR__"banditcamp2",
			]));
		set("item_desc", ([
	        "jing": "�ڹ�¡�˵�ˮ�������ƺ�����������(enter)��ȥ��\n",
	        "well": "�ڹ�¡�˵�ˮ�������ƺ�����������(enter)��ȥ��\n",
	        "��": 	"�ڹ�¡�˵�ˮ�������ƺ�����������(enter)��ȥ��\n",
		]) );
		
		set("objects", ([
			__DIR__"npc/horse" : 1,
		]));
		set("outdoors", "zangbei");

        set("coor/x",-460);
		set("coor/y",620);
		set("coor/z",0);
		set("map","zbeast");
		setup();
}

void init()
{
    add_action("do_enter", "enter");
}

int do_enter(string arg)
{
    object obj,guo;
    object me;

    if(!arg || arg=="")
    {
        write("��Ҫ�������ꣿ\n");
        return 1;
    }
    me = this_player();
    if( arg == "jing" || arg == "well" || arg == "��")
    {
        message_vision("$N׳��׳������û��ע�⣬����һ��������˾��\n", me);
        me->move(__DIR__"jdi");
        return 1;
    }
    else
    {
        write("�㲻������"+arg+"���꣡\n");
        return 1;
    }
}