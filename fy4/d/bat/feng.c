inherit ROOM;
void create()
{
        set("short", "�з�����");
        set("long", @LONG
����һ�����ң���Ȼ���������ûʣ���������ȴ��ʮ�־��µ��壬������һ��
���磬��������һ�ŷ�β�١�����ǽ�Ϲ���һ��������
[1;36m
                        �Ҹ�֪���⣬
                        ����л����

[2;37;0m
LONG
        );
		set("exits", ([ 
  			"west" : __DIR__"huashi",
		]));
        set("objects", ([
       		__DIR__"npc/yuan": 1,
        ]) );
		set("coor/x",0);
		set("coor/y",0);
		set("coor/z",0);
		set("NONPC",1);
		setup();
}

void init()
{
        add_action("do_open", "open");
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
        if( arg == "����" || arg == "ping feng" || arg == "pingfeng")
        {
        me = this_player();
        message_vision("$N���ְ��������ϣ�����΢΢һ��������Ƭ�̣�����
��Ȼ�����ƿ�����¶��һ�����š� \n", me);
        if( !query("exits/south") ) {
        set("exits/south", __DIR__"secret");
        call_out("close_path", 6);
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
        if( !query("exits/south") ) return;
        message("vision","�����������˻�����\n",this_object() );
        delete("exits/south");
}



