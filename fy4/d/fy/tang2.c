inherit ROOM;
void create()
{
    set("short", "�ͷ���");
    set("long", @LONG
��Ǯ��������������̰���ܻߣ��������ǣ���Ϸ��Ů֮��ͽ��������������
��Ӧ�е��Ʋá����о޹��ڽ�Ǯ��ģ�Ҳ���������ܵ��������ʹͺ���Ρ�������
���������            �ͷ�����
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"jhuang",
      ]));

    set("objects", ([
	__DIR__"npc/tiemian" : 1,
//	__DIR__"npc/butou1"  :1,	move to jinan
//	__DIR__"npc/shiye1": 1,
      ]) );
    set("item_desc", ([
	"picture":"ǽ��һ�����߳���������д�š��ͷ��������ĸ����֣��ƺ������ƿ���open����\n",        
	"����":"ǽ��һ�����߳���������д�š��ͷ��������ĸ����֣��ƺ������ƿ���open����\n",
      ]));

    set("coor/x",-200);
    set("coor/y",100);
    set("coor/z",0);
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
    if( arg == "picture" || arg == "����" || arg == "tiaofu")
    {
	me = this_player();
	message_vision("$N����ǽ�ϵ�������������һ�����š�\n", me);
	if( !query("exits/westdown") ) {
	    set("exits/westdown", AREA_MAZE"jq1-entry");
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
    if( !query("exits/westdown") ) return;
    message("vision","�������˻���������ס�˰��š�\n",this_object() );
    delete("exits/westdown");
}


