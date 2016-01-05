#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����");

	set("long", @LONG
�����Ǹ���������̸֮ɫ�������ԣ����˸ߵ�Ұ��������������ҡ�ڲ�����
��Χ��������ض��˺ü�ʮ����ͷ��������ȥ���ܾ�û���˼��룬Ĺ����һ�飬��
һ�鵹�ڵ��ϣ�һ���ưܲ����ľ��󡣺���[37mҰ��[32m�ڷ���ҡ�ڣ���û�˽��µ�·��
LONG);

	set("type","street");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"milin2",
		"north":__DIR__"tomb1",
	]) );

	set("item_desc", ([
                "grass": "Ұ���ڷ�������ҡ�ڣ���ס��ȥ·�������ƺ����Բ���(pushaside)����\n",
                "Ұ��": "Ұ���ڷ�������ҡ�ڣ���ס��ȥ·�������ƺ����Բ���(pushaside)����\n"
        ]) );
        set("objects", ([
                __DIR__"obj/fakecaoren" : 1,
         ]) );
	set("coor/x",-30);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}

void init()
{	object ob;
	string outexit;
	add_action("do_push", "pushaside");
	if( interactive( ob = this_player()))
	{
		if(query("exits/east")) delete("exits/east");
		outexit = __DIR__"milin"+(string)(1+ random(25))+ ".c";	
		set("exits/east", outexit);
	}
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
        if( arg == "Ұ��" || arg == "grass" || arg == "��" )
        {
        	me = this_player();
        	message_vision("$N����·�ߵ�Ұ�ݣ�������һ��������·��\n", me);
 	if( !query("exits/west") ) 
 	{
		set("exits/west", __DIR__"tomb2");
		call_out("close_path", 5);
	}
        return 1;
        }
        else
        {
                write("�㲻���Բ���"+arg+"\n");
                return 1;
        }
}

void close_path()
{
        if( !query("exits/west") ) 
        	return;
        message("vision",
"һ��紵����Ұ���������һ�㣬����ҡ�ڣ��ֵ�ס��ȥ·��\n",this_object() );
	delete("exits/west");
}
