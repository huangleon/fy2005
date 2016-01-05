#include <ansi.h>
inherit ROOM;

int good_luck(object me);
int newbie_help(object me);
void init(){
	object me;
	me = this_player();
	if(interactive(me) && me->query_temp("first_time_login")) {
		me->set("NO_PK",1);
		me->set("marks/newbie_quest",1);
		call_out("newbie_help", 1, me);
	}
	add_action("do_answer", "answer");
}

int newbie_help(object me){
	tell_object(me, WHT"\n\nһ����͵Ĺ�Ʈ������Ȧ���Ǹ���˫��ɫ����С���\n"NOR);
	tell_object(me, WHT"ֻ��С����Ц��ӯӯ��˵��������ӭ�����������磡��λ"+ RANK_D->query_respect(me) + "\n"NOR);
	tell_object(me, WHT"��������ľ���С�������Ƿ���Ҫ��������һ��������������
 ��answer yes/no��\n"NOR);
	me->delete_temp("first_time_login");
	me->set("marks/newbie_intro", 1); 
}

int do_answer(string arg){
	object me;
	
	me = this_player();
	if(!me->query("marks/newbie_intro")){
		return 1;
	}
	if(!arg) {
		tell_object(me, "��ش�answer yes/no����\n");
	} else if(arg == "yes") {
		if(me->query("marks/newbie_intro") == 1){
			tell_object(me, YEL"\nС�����������㽲�������� 
���ֳ���է������Ҫ��Ϥ����������ſ��Խ�����ȥ�� 
��˵˵�������������ʲô�������ô�Ҷ�֪�������� new ���
���磺new ��Һã����������ġ�\n"); 
			me->ccommand("new ��Һã����������ġ�");      
			tell_object(me, YEL"\n�����ֻ�������ǰ����˵ʲô���������ô�Ҷ�֪����������
say ���\n\n���磺" + HIG"say С�������ã�\n\n"YEL"      
С��������˵������������һЩ����������Ҫ��Ҫ������ϸ��
�����أ��� ��answer yes/no��\n"NOR); 
			me->add("marks/newbie_intro", 1);
		} else if(me->query("marks/newbie_intro") == 2) {
			tell_object(me, WHT"\nС����˵�������ðɣ�һ����ҵ�����״̬�ã飬��𣬺�\n");
			tell_object(me, WHT"������Ϳ�ȫ����ʾ������\n");
			tell_object(me, HIR"\n�����ǣ飨����������������������һ�����̣���ס����\n");
			tell_object(me, "Ʒ��ʾ�㴩��������ס����Ʒ��\n"NOR);
			me->ccommand("inventory");
			tell_object(me, HIR"\n����ǣ��\n"NOR);
			me->ccommand("hp");
			tell_object(me, HIR"\n���������������ῴ����\n"NOR);
			me->ccommand("score");
			tell_object(me, WHT"
�ڷ�����������ã�����𣩲쿴���߰�����������Ƿ�������ң�
����ȥ��������ƪ������𡡣������壮����������
�������ǰ�����������Ϸ����֪����������ʲô�ص㣬
���Կ�һ������ƪ������𡡣�ߣ����죮��������
���������Ҳ�ɲο�������𣺣������������������������
���ߵ�������̳����http://www.fengyun.com/fy4bbs/leoboard.cgi��
ϣ������һ�������ķ���֮�á���\n");
			good_luck(me);
		}
	} else {
		if(me->query("marks/newbie_intro") == 1){
			tell_object(me, YEL"
С�������ͷ������λ"+ RANK_D->query_respect(me) +"���ж�������
�ޣ����ˣ����Ƴ������������������㣬���Ƕ���һ����������Ϳ�
�Ժ����Ի��ˡ�ף����ˣ���
˵�꣬С������ʧ�ˡ�\n"NOR);
			me->delete("marks/newbie_intro");
		} else {
			good_luck(me);
		}
	}
	return 1;
}

int good_luck(object me){
	object food, drink;
	if(me->query("marks/newbie_given_food")) {
		return 0;
	}
	tell_object(me, YEL"
С����ЦЦ˵�����ܺã��������ܿ���Ӧ����ġ�
С�������в�֪��ʱ���˸����̵ĺ�«������һ������ĺ�ɫ���ӡ�
С�����Ѷ����ݸ���˵������������һЩʳ�����ˮ��ϣ�������£�
�ޣ����ˣ����Ƴ������������������㣬���Ƕ���һ���������
�Ϳ��Ժ����Ի��ˡ�ף����ˣ���
˵�꣬С������ʧ�ˡ�\n"NOR);
	food = new("/obj/specials/food/redfruit");
	drink = new("/obj/specials/food/calabash");
	food->move(me);
	drink->move(me);	
	me->set("marks/newbie_given_food", 1);
	me->delete("marks/newbie_intro");
}


