#include <ansi.h>
inherit __DIR__"no_killing_place";
#define MINAGE 16
#define MAXAGE 24
#define FATEMARK "����A/��Դ_����"
void create()
{
	set("short", "��������");
	set("long", @LONG
�����ݵصı�Ե����һ��֦Ҷ��ï��С���������Ǳ��̵Ĳݵأ�һ��ƽ���Ĵ�
ʯͷѹ�ڲݵ��ϣ������ɫ��С������ʯͷ���Աߡ�����ʱһ�����С���紵����
������ȫ������һ�������ĺõط���
LONG
	);
	set("long_night", @LONG
���µ��̲ݵ�ϸ�������ڻ谵��ҹ��������Լ���Կ���һ��С����ÿ������
���Ƶ�ҹ����վ������͸��ï�ܵ�֦Ҷ����ɿ��������ǹ⸡����������һ��ƽ
̹�Ĵ�ʯͷ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"lawn",
	]));

	set("item_desc", ([
		"stone" : "ƽ̹�Ĵ�ʯͷ������һ����Ȼ�Ĵ󴲣���������¡���laydown/getup��\n",
		"��ʯ" : "ƽ̹�Ĵ�ʯͷ������һ����Ȼ�Ĵ󴲣���������¡���laydown/getup��\n",
	]) );
	set ("no_magic", 1);
	set("outdoors","taoyuan");
      	set("coor/x",50);
      	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init(){
	::init();
	add_action("do_laydown", "laydown");
	add_action("do_getup","getup");
}

void init_scenery()
{
	remove_call_out("falling_star");
	call_out("falling_star", 1);
}

void add_fate_mark(object ob)
{
	int num = 1 + random(10);
	if(!random(4)) {
		message("vision", HIG"������������ǰ��ɲ�Ǽ�������һ��Ը������\n"NOR, ob);
		message_vision("$NĬĬ��վ��������\n", ob);
		ob->set(FATEMARK, num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) �õ�"+FATEMARK+" "+num+"�� %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}


int do_laydown(){

	object me, walnut,who;
	int i, j;

	me = this_player();
	i = NATURE_D->get_season();
	j = random(20);

	who=query("laydown_person");

	if(me==who) return  notify_fail("���Ѿ�������ѽ��\n");
	if(who&&present(who,this_object()))
		return notify_fail("�Ѿ��������ڴ�ʯ���ˡ�����\n");

	if(i == 1){
		message("vision", "���紵�������������˯����Ȼ��ʯͷ��Ȼ��Щ��ȴ���������ܡ�\n"
				, me);
		message("vision", me->name() + "�����ɵ��˴�ʯ�ϡ�\n", this_object(), me);
		set("laydown_person",me);
	} else if(i == 2  ){
		if(NATURE_D->is_day_time()){
			message("vision", "С����֦Ҷ�����ڵ������⣬�����ʵ��ɵ���ʯ�ϡ�\n", me);
			message("vision", me->name() + "�����ɵ��˴�ʯ�ϣ������̾��һ�ڳ�����\n",
					this_object(), me);
			set("laydown_person",me);
		} else {
			message("vision", "���õ��ǿ�����ô�����ˣ��㲻����Ȼ������\n", me);
/*			if(random(10)<1){
				remove_call_out("falling_star");
				call_out("falling_star", j, me);
			}
*/			message("vision", me->name() + "�����ɵ��˴�ʯ�ϡ�\n", this_object(), me);
			set("laydown_person",me);
		}		
	} else if(i == 3){
		message("vision", "�����ˬ����Ҷ���㣬��������������г����˸��ˡ�\n", me);
		message("vision", me->name() + "���������̾��һ�����������г��������Ρ�\n",
				this_object(), me);
		set("laydown_person",me);
	}
	else if(i == 4){
		message("vision", "������ʯͷ����ٿȻһ������ݺ���Ӳ��������ȥ��\n", me);
		message("vision", "���ɵ�ʯͷ�ϵ�" + me->name() + "���˸���ս�����û����������\n"
				, this_object(), me);
		set("laydown_person",me);
	}

	if(me->query("kar")> 16){
		if (!REWARD_D->riddle_check(me,"����֮��"))
			REWARD_D->riddle_set(me,"����֮��",1);
	    remove_call_out("walnut_fall");
	    call_out("walnut_fall", j, me);
	} else
		tell_object(me,"\n���������Ļ���û��ô��С�������������ģ�������\n\n");
		
	return 1;
}

int do_getup()
{
	object me;

	me=this_player();
	if(me!=query("laydown_person")) return 0;
		remove_call_out("walnut_fall");
	message_vision("$N�Ӵ�ʯ������������\n",me);
	delete("laydown_person");
	return 1;
}

int valid_leave(object who,string dir)
{
	if(who==query("laydown_person"))
		return notify_fail("���������أ�Ҫվ��������getup�������뿪����\n");
	return ::valid_leave(who,dir);
}

void walnut_fall(object me)
{
	tell_object(me,CYN"��֪�����أ����������������硣����������\n"NOR);
	 me->perform_busy(5);
	 call_out("walnut_fall2", 10, me);
}

string view(string room) {
	int i;
	object *inv,env;
	mapping exits;
	string roomdesc, str, *dirs;
	
	env = find_object(room);

	if(!env) env=load_object(room);	
	if (!env) env = load_object(AREA_HUANGSHAN"mroad1"); // Just in case someone removes a room.
	
	str = CYN"\n\nƮƮ���Ƶأ���������һ���̲�������ľ����ڡ�������\n\n\n"NOR;
	
	// room descriptions.
	str += sprintf( "    %s \n",env->query("long"));
	
	str += RED " һ��ϸϸСС�������������ƺ���˭�ں��ȡ�������\n\n\n"NOR;
	return str;
}

void walnut_fall2(object me)
{	
	string *rooms = ({ AREA_HUANGSHAN"mroad1", AREA_HUASHAN"shanlu",AREA_SONGSHAN"lianhua",
			AREA_OLDPINE"spath2", AREA_OLDPINE"spath3",
			AREA_EREN"road1",AREA_ZANGBEI"spring",AREA_EREN"orchard2"});
	string my_room;
	
	if (!stringp(my_room = me->query("marks/turtle_room")))
		my_room = rooms[random(sizeof(rooms))];
	me->set("marks/turtle_room",my_room);
	tell_object(me, view(my_room));
	me->perform_busy(3);
	call_out("walnut_fall3", 6, me);		
}


void walnut_fall3(object me)
{	
	object walnut;
	int num = 1 + random(10);	
	message_vision(WHT"�紵������һ����������������ҵ�$N��ͷ�ϡ�\n"NOR, me);
	message_vision(WHT"$NٿȻһ����һ��µ����������\n"NOR, me);
	if (!me->query("����B/��Դ_����")) {
		me->set("����B/��Դ_����", num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) �õ�����B/��Դ_���� "+num+"�� %s \n",
				me->name(1), geteuid(me), ctime(time()) ));
	}
	walnut = new(__DIR__"obj/walnut");
	walnut->move(this_object());
	delete("laydown_person");
}

void falling_star()
{
	int i, age;
	object ob = this_object();
	object *ppls;
	function f=(:add_fate_mark:);
	message("vision", HIW"ͻȻ֮��һ�����������⻮��ҹ�գ���ʧ���ϱߵ���ʡ�\n"NOR, ob);
	ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && $1->query("age")>=MINAGE && $1->query("age")<=MAXAGE && !$1->query(FATEMARK):));
	if(sizeof(ppls))
		map_array(ppls,f);
}

