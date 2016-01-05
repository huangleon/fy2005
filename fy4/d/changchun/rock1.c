// searoad.c
inherit ROOM;
void create()
{
        set("short", "��ʯ");
        set("long", @LONG
����ɽ�ң����漱�����ȣ�������ӿ��������ǧ�ٿ���ް�Ľ�ʯ������ɽ��
���ǹ�ʯ�϶룬����ն񡣽�ʯ�������ӿ���ȣ�ѩ�׵��˻����ɼ��Ľ���
LONG
        );
		set("item_desc",([
			"rock": "һ���������ʯ���ƺ����԰⶯��(move)\n",
			"��ʯ" :"һ���������ʯ���ƺ����԰⶯��(move)\n",
		]) );
        set("exits", ([ 
	  	"west": __DIR__"rock0",
  		
	]));
        set("outdoors", "tieflag");
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_move","move");
}
int do_move(string arg)
{

    object me;
    if(!arg || arg=="")
    {
    	write("��Ҫ�⶯ʲô��\n");
    	return 1;
    }
    if( arg == "rock" || arg == "��ʯ")
        {
        me = this_player();
        message_vision("$N���˰⽸ʯ����ʯ�������˿�ȥ��\n", me);
        if( !query("exits/down") ) {
        set("exits/down", __DIR__"hole");
        call_out("close_path", 5);
        }
        return 1;

        }
        else
		{
			write("��Ҫ�⶯ʲô��\n");
			return 1;
		}
}
void close_path()
{
        if( !query("exits/down") ) return;
        message("vision",
"��ʯ���˻�������ס�����µĶ��ڡ�\n",
                this_object() );
                delete("exits/down");
}
