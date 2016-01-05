inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��ɫ�İ�������������ʮ�ɣ���ͷ�ʰ����Σ������˰�����ӵ�����γ�һ����
Ȼ�ĺ��塣��ʹ�ڴ����˵�����������Ȼ��������Դ��ƽ������ֵѴ������
���洬�������ˣ�����עĿ��������ͣ��һ�Ҵ󴬣���βһ������ڷ����������죬
��ͷվ�������뺷�ĺ��ӣ�����ĸֵ��������⡣
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"village",
	]));
        set("outdoors", "tieflag");
	set("item_desc", ([
	    "boat" : "���Ϻõĺ�ɼľ�����Φ�촬�������ﴫ������֮������ͷ��һ�����塣\n",
	    "ship" : "���Ϻõĺ�ɼľ�����Φ�촬�������ﴫ������֮������ͷ��һ�����塣\n",
	    "��" : "���Ϻõĺ�ɼľ�����Φ�촬�������ﴫ������֮������ͷ��һ�����塣\n",
	    "��" : "���Ϻõĺ�ɼľ�����Φ�촬�������ﴫ������֮������ͷ��һ�����塣\n",
	    "����" : "ľ��ܽ�ʵ��˳���������ߵ�(walkto)��ͷ(bow)��\n"
	 ]));
	set("coor/x",1020);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}

void init()
{
    add_action("do_walk", "walkto");
}

int do_walk( string arg )
{
	 object me,room;
	 me = this_player();
	 if(!arg || (arg != "bow" && arg != "��ͷ"))
	  	return notify_fail("��Ҫ���Ķ��ߣ�\n");
	 if (this_player()->is_busy())
	 	return notify_fail("��������æ��\n");
	 room = find_object(__DIR__"boatbow");
         if(!objectp(room))
                 room = load_object(__DIR__"boatbow");
	 message_vision("$N������������ͷ��ľ��ܽ�ʵ����������ƽ·�ϡ�\n",me);
	 me->move(room); 
	 return 1;
}
