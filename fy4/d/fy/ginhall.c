inherit ROOM;
void create()
{
    set("short", "�ھ���Ժ");
    set("long", @LONG
һ�䱱���������ĺ�СԺ���ǽ�ʨ�ھֵ���ͷ���������֮�࣬��Ϣ���ɵĵ�
������Χ�м�������С�����ǹ�û�мҵ���������ס�ġ�Ժ�ӵ�����������˵�
���ż���[33m���[32m�������ǵĵ������ҵض���Щ[33m��ϯ[32m��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"ghall",
	"east"  : __DIR__"gke1", 
	"north" : __DIR__"gke2",
	"south" : __DIR__"gke3",
      ]));
    set("item_desc", ([
	"bamboo": 	"��Щ��ͺ������Ų����move bamboo����\n",
	"���" : 	"��Щ��ͺ������Ų����move bamboo����\n",
	"�������" : 	"��Щ��ͺ������Ų����move bamboo����\n",
	"��ϯ":		"�������õ���ϯ�ϻ����˻ҳ����þ�û��������ˣ�move ��ϯ����\n",
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",200);
    set("coor/y",-60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}

void init()
{
    add_action("do_move", "move");
}

int do_move(string arg)
{
    object cock, me, room;

    me = this_player();

    if ( arg == "bamboo" || arg == "���" || arg == "�������") {
	if (me->is_busy())
	    return notify_fail("��������æ��\n");
	me->perform_busy(1);

	if( query("amount") > 10 ) 
	    return notify_fail("��Ų������붼�����ŵ��ܹ��ˡ�\n" );
	cock = new(__DIR__"npc/cockroach");
	if(cock) {
	    cock->move(this_object());
	    message_vision("$NŲ������ͣ�һֻ"+cock->name()+"�ɿ�����˳�����\n", this_player());
	}
	add("amount",1);
	return 1;
    }
    if ( arg == "��ϯ") {
	if (me->query_temp("marks/js_cook_mice") < 4) {
	    message_vision("$NŲ��Ų��ϯ���ֵ���Ժ���ǻҡ�\n",me);
	    return 1;
	}
	if (me->query_temp("marks/js_cook_move")<3) {
	    me->add_temp("marks/js_cook_move",1);
	    message_vision("$N����һ����ϯ������տյ�����ֻ������Ļҳ�����\n",me);
	    return 1;
	}
	me->delete_temp("marks/js_cook_move");
	me->delete_temp("marks/js_cook_mice");
	if ( !objectp(room = find_object(__DIR__"mice_room0")))
	    room = load_object(__DIR__"mice_room0");
	message_vision("$N����һ����ϯ��û�ϵ�����һ������ͨˤ�ڵ��ϡ�\n",me);
	me->unconcious();
	me->move(room);
	return 1;
    }

    return notify_fail("��Ҫ�ᶯʲô��\n");
}

void reset()
{
    ::reset();
    set("amount",0);
}
