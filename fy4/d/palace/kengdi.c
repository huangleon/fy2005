
inherit ROOM;

void create()
{
        set("short", "�ӵ�");
        set("long", @LONG
����һ����ӵĵײ�����������������������Ũ��̧ͷ�������������ա���
�¹�Ӱ���أ�Ҳ��֪�����Ǽ١�תĿ�����������������Ǳ�ʯ�߲�ס��ʯ�ˣ�����
���˵���Ӱ������������Լ���˴�Ϣ���������㲻��ë���Ȼ��
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"keng",
]));
        set("objects", ([
        __DIR__"obj/eren" : 1,
                        ]) );


	set("coor/x",-30);
	set("coor/y",50);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_open", "touch");
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
        if( arg == "statue" || arg == "������" || arg == "��ʯ�߲�ס�Ķ�����"
        	|| arg == "eren" )
        {
        me = this_player();
        message_vision("$N�����������������ְ��˰���ϵ�ʯ��
��ѽ����һ������ӱߵ�ʯ���ϣ����ѿ���һ���Ż���\n", me);
        if( !query("exits/east") ) {
        set("exits/east", __DIR__"secretpath0");

        REWARD_D->riddle_done( me, "�������", 10, 1);
        
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("�����ְ��˰�"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/east") ) return;
        message("vision",
"ʯ���ϵ��Ż���������Ϣ�ĺ���������\n",
                this_object() );
                delete("exits/east");
}

