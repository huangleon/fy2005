// Room: /d/oldpine/clearing.c

inherit ROOM;

void create()
{
        set("short", "�ּ�յ�");
        set("long", @LONG
����һ���ּ�յأ���ľ�������Ǳ����޼���һ�㣬�������յ�Χ��һ������
��Բ�Σ��յ�����һ��޴��������ƽ���ϳ���һ�Ѵ�ɡ��������Ҷï�ܵ���ȥ��
�������⣬�յ�����������С·�ֱ�ͨ�����������������������ϵ�С·����
��һ�����ӡ�
LONG
        );
        set("item_desc", ([
                "����": "һ���ָ��ִ������������̧ͷ���Ͽ���ʱ���ƺ��и���Ӱ\n"
                                "������֮���ƶ�������Ҳ���Ƿ紵������ɵĴ����\n",
                "����": "���˵���������������\n"
        ]) );
        set("exits", ([
                "west" : "/d/oldpine/npath3",
                "south" : "/d/oldpine/spath1",
                "east" : "/d/oldpine/epath1"
]));


	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",30);
	setup();
}

void init()
{
        add_action("do_climb", "climb");
        if( this_player() ) {
                tell_room(__DIR__"tree1", this_player()->name() + "���������˹�����\n");
        }
}

int do_climb(string arg)
{
		if (this_player()->is_busy()) {
			tell_object(this_player(),"��������æ��\n");
			return 1;
		}
		
        if( arg!="pine" && arg != "tree" && arg!= "����" && arg!="������"){
        	tell_object(this_player(),"����Ҫ��ʲô��\n"); 
        	return 1;
		}
        message_vision("$N�ֽŲ��ã����ݵ������˿յ�����Ĵ�������\n",
                this_player());

        tell_room(__DIR__"tree1", this_player()->name() + "����������������\n");
        this_player()->move(__DIR__"tree1");
        return 1;
}

int valid_leave(object me, string dir)
{
        tell_room(__DIR__"tree1",
                "���µ�" + me->name() + "��" + to_chinese(dir) + "�뿪�ˡ�\n");
        return 1;
}
