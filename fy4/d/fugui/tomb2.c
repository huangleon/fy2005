inherit ROOM;

void create()
{
	set("short", "�����");

	set("long", @LONG
�����Ǹ���������̸֮ɫ�������ԣ����˸ߵ�Ұ��������������ҡ�ڲ�����
��Χ��������ض��˺ü�ʮ����ͷ��������ȥ���ܾ�û���˼��룬Ĺ����һ�飬��
һ�鵹�ڵ��ϣ�һ���ưܲ����ľ���
LONG);

	set("type","street");
	set("outdoors", "fugui");
	set("exits",([
		"northwest":__DIR__"tomb4",
		"southwest":__DIR__"tomb3",
		"east":__DIR__"tomb",
	]) );
	set("objects", ([
                __DIR__"obj/fakecaoren" : 1,
         ]) );
	set("coor/x",-40);
	set("coor/y",160);
	set("coor/z",0);
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
        if( arg == "������" || arg == "ren" || arg == "����" )
        {
        	me = this_player();
        	message_vision("$N���˲�·�ߵĵ����ˣ��������������һ�㣬����ҡ�ڡ�\n", me);
        	return 1;
 	}
 	else
        {
                write("�㲻���Բ���"+arg+"\n");
                return 1;
        }
}