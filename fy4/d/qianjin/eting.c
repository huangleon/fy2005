inherit ROOM;
void create()
{
        set("short", "��ƫ��");
        set("long", @LONG
�����޴������Զ��ۺ�����ҫ������һ��Сľ̨��̨��һ���ƣ����������¡�
�ҽ�һС��[33m��̺[32m��̺ɫ�ʺ졣�����֧ľ�ܣ������г����Ͼơ�����һ��С������
�����˳���ס����������ӡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"west" : __DIR__"tading",
	]));
        set("item_desc", ([
                "carpet": "���С����̺�ƺ���������(pull)��\n",
                "ditan": "���С����̺�ƺ���������(pull)��\n",
                "��̺": "���С����̺�ƺ���������(pull)��\n",

        ]) );
	set("NONPC",1);
        set("objects", ([
        __DIR__"npc/guard" : 1,
                        ]) );

	set("coor/x",-60);
	set("coor/y",15);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_pull", "pull");
}

int do_pull(string arg)
{
	object ob;
	object sect;
	if ( !arg && arg != "carpet" && arg != "ditan" && arg != "��̺")
                return 0;
        if( ob = present("boater", this_object()))
         if (ob->query("name")=="�����")
        {
        	message_vision("$N��$n˵��������Ϲæ���ȣ�\n", ob, this_player());
        	return 1;
        }
        if( !query("exits/down") ) {
        message_vision("$N�ѵ�̺����������һ���ܵ���\n", this_player());
      
        set("exits/down", __DIR__"secret_room");
		sect = find_object(__DIR__"secret_room");
		if( ! sect)
        	sect = load_object(__DIR__"secret_room");
		if( sect )
        	sect->set("exits/up", __FILE__);
			call_out("close_path",15);
        }
        else
        {
       		message_vision("$N�ѵ�̺�������ڸ�ס�ܵ���\n", this_player());
        	delete("exits/down");
        	sect = find_object(__DIR__"secret_room");
        	if( ! sect)
        	sect = load_object(__DIR__"secret_room");
		if (sect)
        	sect->delete("exits/up");
        }
        return 1;
}

void close_path()
{
	object sect;
        if( !query("exits/down") ) return;
                delete("exits/down");
        sect = find_object(__DIR__"secret_room");
        if( ! sect)
        sect = load_object(__DIR__"secret_room");
        if (sect)
        sect->delete("exits/up");

}

