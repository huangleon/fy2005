
inherit ROOM;

void create()
{
        set("short", "���տ�");
        set("long", @LONG
���տڲ�����������,���ܹ͵������յ��ˡ�ɳĮ���д�ٵķ˰�����Ķ��桢
��ת�ۼ��ûһ�������ɳ������û�о��������˵��ɳĮ�Ǹ����µ���ȥ�޻ص�
�ط�����ֻҪ�뵽��������յĺ��ӣ���һ���ܰ�ȫ׼ʱ�ص������Ŀ�ĵء�
LONG
        );
        set("exits", ([ 
 		"west": __DIR__"fair2",

	]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/xiaopan": 1,
                __DIR__"npc/shituo": 1,
        ]) );
	set("coor/x",-1025);
	set("coor/y",-10);
	set("coor/z",0);
	set("route_clear",1);
	set("bandit_name","����կ");
	setup();

}

void init_scenery()
{
     call_out("bandit_out",1);
}

void bandit_out() {
    string *bandit = ({"����կ","����","���ɱ�" });
	string band;
	
	if (query("route_clear")) {
		band = bandit[random(sizeof(bandit))];
		set("route_clear",0);
		set("bandit_name",band);
		//CHANNEL_D->do_sys_channel("info","����ɳĮ�����ն��������ͽ��ɱ����һ������"); //��ֹ�������robot�ʾ�������ʾ
	}
}


int go_out_1(object me, int stage) {
	object room;
	string *route = ({AREA_QUICKSAND"saikou", AREA_QUICKSAND"saiwai2", 
				AREA_QUICKSAND"yangguan", AREA_ZANGBEI"kunlun1",
				AREA_TAIPING"mroad1", AREA_TAIPING"yizhan", 
				AREA_TAIPING"stable" });
	string *dir = ({ "��","��","��","��","��","��","��" });
	
	if (!me || me->is_ghost())	return 1;
		
	if (me->is_ghost()||me->is_fighting()) {
		tell_object(me,"�������������������\n");
		me->stop_busy();
		me->delete_temp("ride");
		return 1;
	}
	
	room=find_object(route[stage]);
	if(!objectp(room)) room = load_object(route[stage]);
        message_vision("$N����������"+dir[stage]+"�뿪��\n",me);
        me->move(route[stage]);
        message_vision("$N�����������˹�����\n",me); 
//	write ("stage is "+stage+" route is "+sizeof(route)+"\n");
	stage++;
	if (stage == sizeof(route)) {
		message_vision("������һ��ߺ�ȣ������ˣ���\n",me);
		message_vision("$N�����ձ���һԾ���¡�\n",me);
		me->delete_temp("ride");
		me->stop_busy();
		return 1;
	}
	call_out("go_out_1",2,me, stage);
    return 1;
}

