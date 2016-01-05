inherit DOOR_ROOM;
#include <room.h>
void create()
{
    set("short", "�ھ��˷�");
    set("long", @LONG
�����ǽ�ʨ�ھֳ����������˷��������������ɼ�Ӳ�Ļ���ʯ���ɵġ���Ψһ
��һ��С���϶�����Ĵָ��ϸ�ĸ������ݽ���С��������������ͷ�����ŵ�����ҹ
���ء�������ˣ����л��л�ͭ���壬����һ�죬�ھֻ���Ǿͻ��ӵ������
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"ghall",
      ]));
    set("objects", ([
	__DIR__"npc/xiansheng" : 1,
      ]) );
    set("item_desc", ([
		"bed": "���С���ƺ������ƿ�(push)��\n",
		"��": "���С���ƺ������ƿ�(push)��\n",
		"С��": "���С���ƺ������ƿ�(push)��\n",
		"bell" : "���������ҡҡ(ring)��\n",
		"��" : "���������ҡҡ(ring)��\n",
		"����" : "���������ҡҡ(ring)��\n",
		"��ͭ����" : "���������ҡҡ(ring)��\n",
      ]) );
    set("coor/x",180);
    set("coor/y",-40);
    set("coor/z",0);
    set("map","fyeast");

    setup();
    create_door("south", "door","����", "north", DOOR_CLOSED);

}

void init()
{
    add_action("do_ring", "ring"); 
    add_action("do_push", "push");
}

int do_ring(string arg)
{
    int i;
    object ob;
    if ( !arg || (arg != "bell" && arg != "��ͭ����" && arg != "����" && arg != "��"))
    {
		return notify_fail("��Ҫҡʲô��\n");
    }	
    message_vision("$N����ҡ��ҡ��ͭ���壮����\n", this_player());
    if( !(int) query("notyet"))
	for(i;i<=random(3)+1;i++)
	{
	    ob = new(__DIR__"npc/resting_biao");
	    if(ob) ob->move(this_object());
	    message_vision("$N���˽���������\n", ob);
	    ob->kill_ob(this_player());
	    set("notyet",1);
	}
    return 1;
}

int do_push(string arg)
{
    object ob;
    object sect;
    if ( !arg || ( arg != "bed" && arg != "С��" && arg != "��"))
	return notify_fail("��Ҫ��ʲô��\n");

    if( ob = present("xian sheng", this_object()))
    {
		message_vision("$N�ú�һ����ֵ���������$n��\n", ob, this_player());
		return 1;
    }
    
    if( !query("exits/down") ) {
		message_vision("$N��С���ƿ�������һ���ܵ���\n", this_player());	
		set("exits/down", __DIR__"secret_room");
    }
    else
    {
		message_vision("$N��С���ƹ����ڸ�ס�ܵ���\n", this_player());
		delete("exits/down");
    }
    return 1;
}
