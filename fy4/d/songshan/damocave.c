// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
#include <skill.h>
inherit ROOM;
void create()
{
        set("short", "��Ħ����");
        set("long", @LONG
����һ���߿����ųߣ����Ȳ�����ɵ���Ȼʯ���������Ķ��ţ�����������
����ʹ�����ﶬů������������ˬ�����п���һ�ֻ�ǵ����и�����״��Բʯ��
��ĥ�÷��⡣��֪���ڴ�Ħ���ж��ٸ�ɮ���������(�������)����
LONG
        );
	set("exits", ([ 
		"out" : __DIR__"damo",
	]));
//	set("no_fight", 1);
	set("in_mianbi", 0);
	set("coor/x",63);
	set("coor/y",26);
	set("coor/z",0);
	setup();
}
void init(){
	add_action("do_mianbi", "mianbi");
	add_action("do_look", "look");
	add_action("do_study", "study");
}

int do_study(string arg){
	object ob, me;
	mapping skill;
	string book, liter;
	int cost, sena;
	int amount=0;
	int my_skill;
	me = this_player();
    if( me->is_fighting() )
        return notify_fail("���޷���ս����ר�������ж���֪��\n");
    if( me->is_busy() )
        return notify_fail("����һ��������û����ɣ������ж���֪��\n");

    if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
        return notify_fail("ָ���ʽ��study <��Ʒ> <������>\n");
    if(book != "print"){
    	return 0;
    }
    if(book == "print" 
		&& !REWARD_D->check_m_success( me, "�������")) {
//    	&& !me->query("marks/����_��ڳɹ�")) {
		tell_object(me, "��ʲô��������������ôѧ�أ�\n");
    	return 1;
    }
	ob = present("print", this_object());
    if(!objectp(ob))
    	return notify_fail("��Ҫѧʲô��\n");
	return 0;
}     
	


int do_mianbi(){
	object me;
	me = this_player();

	if(me->is_fighting()){
		return notify_fail("ս���в�����ڡ�\n");
	}
	if(me->is_busy()){
		return notify_fail("������æ��\n");
	}

	message_vision("$N��������Բʯ�ϣ��۾��۾�����ؿ���ʯ�ڡ�\n", me);
	me->set_temp("disable_inputs", 1);
	me->add_temp("block_msg/all", 1);
	me->set_temp("is_unconious", 1);
	me->set("disable_type", HIG "<�����>"NOR);
	me->set_temp("in_mianbi", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_mianbi", me :), 8 + random(10));
	return 1;	
}

void remove_mianbi(object me){
	object obj;
	int i;
	me->delete_temp("disable_inputs");
	me->delete("disable_type");
	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);
	me->delete_temp("in_mianbi");
	me->delete_temp("is_unconcious");
	if (REWARD_D->check_m_success( me,"�������")) {
//	if(me->query("marks/����_��ڳɹ�")) {
		tell_object(me, HIG"\nʯ����������ԼԼ��ʾ��һ������( ����������\n"NOR);
		if(!present("damo print", this_object())){
			obj = new(__DIR__"npc/damo");
			obj->move(this_object());
		}
		return;
	}
	if(!me->query("marks/�������")){
		tell_object(me,"��ʲôҲ�о���������\n");
		return;
	}
	if(!random(5)){
		if(!me->query("marks/�������")){
			tell_object(me, "��������ˣ�����ס������˫�ۣ���������·����������ڶԻ���\n"); 
			tell_object(me, "\n�ʣ������޺η������ý��ѣ���\n"); 
			tell_object(me, "�𣺡�Ψ�ж���һ�ţ����ý��ѡ���\n"); 
			tell_object(me, "�ʣ����ƺ�Ϊ���򣿡�\n");
			tell_object(me, "�𣺡����ߣ��ٳ�������ߣ��������á���\n"); 
			tell_object(me, "�ʣ����Ӻζ��ޣ���\n"); 
			tell_object(me, "�𣺡��Ӹ����ޡ���\n"); 
			tell_object(me, "�ʣ����ƺδӸ����ޣ���\n");
			tell_object(me, "�𣺡���Ϊ��������\n");
			tell_object(me, "\n���Ȼһ���亹�����˹������������Լ�ԭ��������Բʯ�ϡ��ղ� 
�������ѵ�ֻ���Ͽ�һ�Σ�\n");
			me->set("marks/�������", 1);
		} else if (me->query("marks/�������") == 1) {
			tell_object(me, "��������ˣ�����ס������˫�ۣ���������·����������ڶԻ���\n"); 
			tell_object(me, "\n�ʣ����ƺν����ģ���\n"); 
			tell_object(me, "�𣺡��޽����ģ������޽����ģ����������Ҳ�����ƣ�����Ӧ�ᣬ�ο��Ƿ�Ҳ���������У�
�Ƿ�����Ҳ������ȡ���ޣ�������ѡ��� \n");
			tell_object(me, "�ʣ����ƺεõ�����\n"); 
			tell_object(me, "�𣺡��ԱϾ���Ϊ�á���\n"); 
			tell_object(me, "�ʣ����ƺ��ǱϾ��ã���\n"); 
			tell_object(me, "�𣺡��޵����޵ã������Ͼ��á���\n"); 
			tell_object(me, "�ʣ����ƺ��ǱϾ��գ���\n"); 
			tell_object(me, "�𣺡��޿����޿գ������Ͼ��ա���\n"); 
			tell_object(me, "\n�������۾���һ�㣬���ֲ�û��������Χ˵����\n"); 
			me->set("marks/�������", 2);
		} else if(me->query("marks/�������") == 2) {
			tell_object(me, "��������ˣ�����ס������˫�ۣ���������·������и��ͳ��Ķ��º͵������ڶ���˵��\n"); 
			tell_object(me, "ν�޵����ˣ����ܿ�ʱ�����������Ҵ������������У�������ĩ���������У�����Թ����\n");
			tell_object(me, "Υ�����ޣ������޷������������ҵ���죬����������룬�������ܣ�����ԩ�ߡ����ƣ�\n");
			tell_object(me, "��಻�ǣ����Ĺʣ�ʶ��ʣ�������ʱ��������Ӧ����ԩ��������˵�Ա�ԩ�С�\n");	 
			tell_object(me, "\n���Ȼ���ѣ���������δ�ԡ���Ȼ֮���Ȼ����\n"); 
			me->set("marks/�������", 3);
		}
		me->delete("marks/�������");
		return;
	} 
	switch(random(3)){
		case 0:
			message_vision("$N���˿������������һ�����ȡ�\n", me);
		break;
		case 1:
			message_vision("$N������ͷ��վ��������\n", me); 
		break;
		case 2: 
			message_vision("$N�������۾���������ʯ���Ͽ�����ʲô���������ۻ��ˡ�\n", me);
		break;
	}
}

int valid_leave(object obj, string dir){
	object room;
	room = find_object(__DIR__"damo");
	if(!objectp(room)){
		room = load_object(__DIR__"damo");
	}
	if(dir == "out" && present("guard monk", room)){
		if(obj->query("marks/�������")){
			message_vision(YEL"�����ػ�ɮ��$N˵��������λʦ�壬������������ڶ������˼��������\n"NOR, obj);
			message("vision", YEL"�ػ�ɮ���Ŷ���˵��������λʦ�壬������������ڶ������˼��������\n"NOR, room);
			return 1;
		}
	}
	return 1;
}
