
inherit ROOM;
void cloth_path();
void create()
{
        set("short", "С��");
        set("long", @LONG
��������ů�紺�����ϵ�ƿ���ﻹ���ż�֧��÷�������ڴ����Х������ȴ��
���Ĺ��š��������Ų�ľ�壬ľ���¾��Ǳ������ߵ��ɻ�����
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"yingou",
]));
        set("item_desc", ([
                "floor": "���ľ���ƺ���������(pull)��\n",
                "ľ��": "���ľ���ƺ���������(pull)��\n",
                "muban": "���ľ���ƺ���������(pull)��\n",

        ]) );

	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
void init()
{
        add_action("do_open", "pull");
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "floor" || arg == "muban" || arg == "ľ��")
        {
        me = this_player();
        message_vision("$N������ϵ�ľ�壬���������ǿյġ�\n", me);
        if( !query("exits/down") ) {
        set("exits/down", __DIR__"secret");
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("�㲻���Դ�"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/down") ) return;
        message("vision",
"ľ���ֵ��˻�������ס�˼м䡣\n",
                this_object() );
                delete("exits/down");
}

