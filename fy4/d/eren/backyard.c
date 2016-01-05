inherit ROOM;
#include <ansi.h>
void guard_out(object me);

void create()

{
        set("short", "��Ժ");
        set("long", @LONG
��Ժ������һ������˵��ݣ�����һ�˶�ߣ�ͨ�����ӵ��Ž����ر��ţ���
�ȴ����ð�ֽ�ɵ�����ʵʵ���ƺ������˿��⡣Ժǽ���ߣ����泤�������١���ֻ
��ȸ�ڵ��ϱı�������Ѱʳ�ԡ�
LONG
        );
        set("exits", ([ 
			]));
        set("objects", ([
	]) );
	set("item_desc", ([
                "����": "���ݺ��ң��ƺ��Ǽ���ææ����ȥ�ģ���������ж������䶯��\n",
                "straw": "���ݺ��ң��ƺ��Ǽ���ææ����ȥ�ģ���������ж������䶯��\n",
                "daocao": "���ݺ��ң��ƺ��Ǽ���ææ����ȥ�ģ���������ж������䶯��\n",
                "��ȸ": "��ֻ��ȸ�ڵ��ϱı�������Ѱʳ�ԡ�\n",
                "bird": "��ֻ��ȸ�ڵ��ϱı�������Ѱʳ�ԡ�\n",
                "sparrow": "��ֻ��ȸ�ڵ��ϱı�������Ѱʳ�ԡ�\n",
                "door": "�Ź��ţ���֪�Ƿ�����Դ�(open)��������������˷����˿ɲ����С͵������\n",
                "��": "�Ź��ţ���֪�Ƿ�����Դ�(open)��������������˷����˿ɲ����С͵������\n",
                "Ժǽ":	"ǽ���ߣ�ץ�����ٿ�������ȥ��\n",
                "����":	"ǽ���ߣ�ץ�����ٿ�������ȥ��\n",
                "vine":	"ǽ���ߣ�ץ�����ٿ�������ȥ��\n",
                "wall":	"ǽ���ߣ�ץ�����ٿ�������ȥ��\n",
        ]) );
	
	set("spider_out",0);
	set("coor/x",80);
        set("coor/y",75);
        set("coor/z",0);
	set("map","eren");
	setup();
	
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_search","search");
	add_action("do_look","look");
	add_action("do_open","open");
	add_action("do_listen","listen");
}

int do_listen(){
	tell_object(this_player(),"�����ƺ���������˽���ϧ����̫�����\n");
	return 1;
}

int do_climb(string arg)
{
   	object me, room;

   	me = this_player();
   	if(!arg || (arg != "wall" && arg !="Ժǽ" && arg!="vine" && arg!="����")){
   		tell_object(me,"��Ҫ���Ķ�����\n");
   		return 1;
   	}
   	
   	if (me->is_busy()|| me->is_fighting()) {
   		tell_object(me,"������û����ǽ��\n");
   		return 1;
   	}
   	message_vision("$Nץס���ܣ������ش�Ժǽ�����˳�ȥ��\n\n", me);
	call_out("climb_out",3,me);
	me->start_busy(2);
   	return 1;
}

void climb_out(object me) {
	object room;
   	if (me->is_ghost()) return;
   	room = find_object(__DIR__"groad3"); 
   	if(!objectp(room)) room=load_object(__DIR__"groad3");
      	me->move(room);
    message("vision",me->name()+"��Ժǽ�Ϸ��˹�����\n", environment(me), me); 
    return;
}

int do_search(string arg) {
	object me, man, ouyang;
	
	me=this_player();
	if(!arg || (arg != "straw" && arg !="daocao" && arg !="����")){
		tell_object(me,"�����Ǹ�������\n");
   		return 1;
   	}
   	if (me->is_busy()) {
   		tell_object(me,"��������æ��\n");
   		return 1;
   	}
   	if (ouyang = present("ouyang ding",this_object())) {
		tell_object(me,"����Ц�ɣ����˾�����ǰ��\n");
		return 1;
	}
   	if (query("spider_out")) {
   		message_vision("$N���ҵؽ����ݲ���������¶��һ����ס�����ף�����տ���Ҳ��\n",me);
   		return 1;
   	}
	message_vision("$N���ҵؽ����ݲ���������¶��һ����ס�����ף�������һ�����ź�ɫ�����µ��ˡ�\n",me);
	man = new(__DIR__"npc/spider");
	man->move(this_object());
	call_out("spider",2,me);
	me->start_busy(2);
	return 1;
}


void spider(object me) {
	object man;
	if (man=present("spiderman",this_object())) {
	call_out("event2",2,me);
	set("spider_out",1);
	me->start_busy(3);
	}
}

string *event2_msg=	({
	CYN"������һ���֣����������л�����º�֩�룬���ն������𡣡�\n"NOR,
	CYN"�����˹�ò��ƽ�ͣ�ʵ��ɱ��������С�ܰ���׷�������������ʧ����Ӱ��̤��ʱ
ȴʧ�ֱ�ŷ���ֵ���ס�����Ǵ���������������������\n"NOR,
	CYN"����С������̤�����ã����˹���������ͨ������ڱ������������֮������\n"NOR,
	CYN"��ɽ��ˮ�����ʹ˱�������в�ǲ������Ƽ�ô�Ѱ�ҡ���\n"NOR,
	BLU"��֩��˵�գ�ͻȻһ���֣�ֻ��������з·����������������˿����ֱ���˳�ȥ��
������һ�������Ѹ��ŷ��˳�ȥ�������Ǽ�һ��Ĳ����ˣ�����˿Ҳ�����ˡ�\n"NOR,
	});


void event2(object me, int count)
{
	object man;
	if (environment(me)!=this_object()) return;
	tell_object(me,event2_msg[count]+"\n");
	if(++count==sizeof(event2_msg))
	{
		if (man=present("spiderman",this_object())) 
			destruct(man);
		if (!REWARD_D->riddle_check(me,"С����ҽ") && !REWARD_D->check_m_success(me,"С����ҽ"))
			REWARD_D->riddle_set(me,"С����ҽ",1);
		return;
	}
	else call_out("event2",1,me,count);
	return ;
}

void reset()
{
     	::reset();
       	set("spider_out",0);
} 

int do_look(string arg)
{
   	object me, room, ouyang;

   	me = this_player();
   	if(!arg || (arg != "window" && arg !="����"))
   		return 0;
   	if (ouyang = present("ouyang ding",this_object())) {
		message_vision("ŷ�������һ������ʲô��\n",me);
		return 1;
		}
   	message_vision("$N������ŵ��ߵ����¡�\n\n", me);
	if (query("showing")) {
		tell_object(me,"�����Ѿ������ڴ���͵����Ү��\n");
		return 1;
		}
	message_vision("��Ȼ�����ﴫ��������$N��æ������ȥ��\n\n",me);
	call_out("event1",3,me);
	set("showing",1);
	me->start_busy(2);
   	return 1;
}

string *event1_msg=	({
	CYN"��������������˺ܶ࣬����Ҫ����С�Ĵ��£���Ҫ¶�˺ۼ�����\n"NOR,
	MAG"����������С��������Ӧ��������������æ��һ�󡣡�\n"NOR,
	CYN"���ٺ٣�����������һ�֣�����û��Ͱ��˲�ǲ������ת����\n"NOR,
	MAG"��û���������ǻ��������Ǵ����ѳ��˰˷֣�����������������������\n"NOR,
	CYN"����Ժ���Ǹ���δ��ã���\n"NOR,
	MAG"��ɱ�����¹�ϵ�ش󣬲�������ڡ���\n"NOR,
	CYN"���������⹷�������Ǻ��ĺÿ࣬���Ű׻��������Ӳ��ܻ���ȴҪĥʲô��ƨ��������\n"NOR,
	MAG"�����̼���ɣ�����³ɣ�����û���ֵܵĺ����ӹ�����\n"NOR,
	CYN"����һ����ʲôʱ���������ͣ���\n"NOR,
	MAG"���꣬С�ĸ�ǽ�ж�����������������������\n"NOR,
	BLU"����Խ��Խ�ͣ��Ų�������Զȥ�ˡ�\n"NOR,
	});


void event1(object me, int count)
{
	if (!me || environment(me)!=this_object()) {
		delete("showing");
		return;
	}
		
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		delete("showing");
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}


int do_open(string arg) {
	
	object me;
	object ouyang;
	if (!arg || (arg!="door" && arg!="��")) 
		return 0;
	me = this_player();				
	if (me->is_busy())	{
		tell_object(me,"��������æ��\n");
		return 1;
	}
	message_vision("$N������ŵ��ߵ��űߣ��������Ű���ȥ��\n",me);
	if (query("showing")){
		message_vision("����ʲôҲû�з�����\n",me);
		return 1;
	}
		
	if (ouyang = present("ouyang ding",this_object())) {
		message_vision("ŷ�������һ������ʲô��\n",me);
		return 1;
		}
	
	message_vision(HIR"ͻȻ���ѵ�һ�����ź���������ˡ�\n"NOR,me);
	guard_out(me);
	return 1;
}

void guard_out(object me) {
	object guard;
	if (!guard = present("ouyang ding",this_object()))
	{
		guard = new(__DIR__"npc/ouyang1a");	
		message_vision("ŷ����ͻȻ����������ǰ��\n",me);
		message_vision("ŷ�����ȵ������컯�գ������������ԣ���\n",me);
		guard->move(this_object());
		guard->kill_ob(me);
	}
	return;
}		
