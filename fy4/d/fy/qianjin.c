inherit ROOM;
int check_container(object ob);
void create()
{
    set("short", "ǧ��¥��");
    set("long", @LONG
��¥�䲻�ھ�������ȴ����ԭ����������¥�����������ľƣ�Ҳ����õľƣ�
����������Ů�ˣ�Ҳ������ζ����Ů�ˣ����������ķ���Ҳ����õķ���
���������ƣ�����һ�飬�ָ���һ�����ͽ��ң�
[1;35m
			��ɫ�ޱ�
[2;37;0m
LONG
    );
    set("exits", ([
	"east" : __DIR__"huanyun3",
	"west" : AREA_QIANJIN"pingfeng",
      ]));
    set("item_desc", ([
	"sign": @TEXT
ǧ��¥¥�棺
�������ɼд��κα�����¥��
�����Է�����ǧ��¥С������Ϊû������������
�������ɼд��κ�ʳ���ˮ��¥��
������ҳ������������ѣ��໥�������ӣ�
������ܣ�������¥�洦�á�
��������ͷ������Խ�࣬���ܵ��ź�Խ�á�

���»�����һ��д������ŤŤ�����ֵ�Сֽ��(paper)��
TEXT
,
	"paper": @TEXT
Сֽ��������ŤŤд�ţ�
���˷��㣬�Լ����㣬��ʮ�����ӣ���Ҷ����㡣
TEXT
      ]) );

    set("outdoors","fengyun");
    set("NONPC",1);
    set("objects", ([
	__DIR__"npc/guinu" : 2,
      ]) );
    set("coor/x",-80);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");
    setup();
}

int valid_leave(object me, string dir)
{
    object *inv, ob;
    int i, dayPhase;

    if(dir == "west") {
	if(!ob = present("gui nu",this_object())) {
	    ob = new(__DIR__"npc/guinu");
	    if(ob) {
		ob->move(this_object());
		message_vision("һ����ū��ǧ��¥��ӭ�˳�����\n", me);
	    }	
	}

	if (me->query_temp("annie/pay_guinu"))
	{
		me->delete_temp("annie/pay_guinu");
		me->set("food",0);
		me->set("water",0);
		message_vision("��ūת��ͷȥ����װʲôҲû�п�����\n", me);
		return 1;
	}

	dayPhase = NATURE_D->get_current_day_phase();
	if(dayPhase > 0 && dayPhase < 6) {
	    message_vision("��ū�����죬��$NЦ��˵��ʱ�����磬�����ǻ���˯����������\n", me);
	    return notify_fail("����һ�°ɣ�\n");
	}
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
	    if(((int)inv[i]->query("weapon_prop")) ||
	      ((int)inv[i]->query("food_remaining") != 0) ||
	      ((int)inv[i]->query("liquid/remaining") !=0) ||
	      ((int)inv[i]->is_container()))
		return notify_fail("��ū����Ц����ǧ��¥��ǧ��¥��¥�棬���뿴�ƣ�\n");
	}
	me->set("food",0);
	me->set("water",0);
    }
    return 1;
}
