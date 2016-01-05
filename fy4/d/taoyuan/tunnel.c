#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���°���");
        set("long", @LONG
��ΧһƬ��ڣ������ˮ���а���������������磬������ë���Ȼ���ֺ�
�������ж����ϤϤ�������������������Ե�����ֲ���ˮ�������㲻֪Ҫͨ���
�������˫�ֺ��ҵ������ţ����г����˿־壬�и���������Ҳ��ѽ���㲻������
���Ϊʲôû��Щ�����Ķ���������
LONG
        );
	set("no_magic",1);
	set("coor/x",-20);
	set("coor/y",-50);
	set("coor/z",-20);
        setup();
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg)
{
	object me, room, book,frog;

	me = this_player();

	switch (random(5)) {
		case 0:
			tell_object(me,"���ںڰ����Ĵ�������ȴʲô��û�з��֡�\n");
			break;
		case 1:
			tell_object(me,RED "���ںڰ����Ĵ�������ͻȻ��о�����ʲô�������������ҧ��һ�ڡ�\n"NOR);
			message_vision(YEL "$N�ںڰ��з���һ�����С�  ��....������......\n"NOR, me);
			me->receive_damage("kee",50);
			me->set_temp("last_damage_from","����Դ���ﱻС����ҧ���ˡ�\n");
			break;
		case 2:
			tell_object(me, RED"��һ��С�Ļ�������ˮ�ֻ����һ�ɺܴ������������ȥ��\n"NOR );
			tell_object(me,YEL"����е��в�����......ˮ�����������롣\n"NOR);
			message("vision", "�ںڰ�����������ͨһ����ֻ��"+me->name()+"����Ӱ���Ա�һ���Ͳ����ˡ�\n" , environment(me),me);
			me->receive_damage("sen",30);
			me->set_temp("last_damage_from","����Դ���ﱻС����ҧ���ˡ�\n");
			me->move(__DIR__"well");
			message("vision",me->name() + "ͻȻ��ˮ�����˳�����\n", environment(me),me);
			break;
		case 3:
			if((REWARD_D->riddle_check(me,"�ž�����") == 1
				|| REWARD_D->riddle_check(me,"�ž�����") == 2)
				&& !me->query_temp("marks/taoyuan/get_skull")) { 
				tell_object(me,"���ںڰ��к���Ŀ�ĵ��Ĵ�������ͻȻ��о������ƺ������˸�Բ�Ķ�����\n");
				tell_object(me,"��Ͽ�����������˻��\n", environment(me),me);
				message("vision","�ںڰ���������һ��ϤϤ������������"+me->name()+"�ƺ������ﴧ��Щ������\n", environment(me),me);
				me->set_temp("marks/taoyuan/get_skull",1);
				book = new(__DIR__"obj/head");
				book->move(me);

				REWARD_D->riddle_set(me,"�ž�����",2);
			}
			else {
				tell_object(me,RED "���ںڰ����Ĵ�������ͻȻ��о�����ʲô�������������ҧ��һ�ڡ�\n"NOR);
				message_vision(YEL "$N�ںڰ��з���һ�����С�  ��....������......\n"NOR, me);
				me->receive_damage("kee",50);
				me->set_temp("last_damage_from","����Դ���ﱻС����ҧ���ˡ�\n");
			}
			break;
		case 4:
				tell_object(me,RED "���ںڰ����Ĵ�������ͻȻ��о�����ʲô�������������ҧ��һ�ڡ�\n"NOR);
				message_vision(YEL "$N�ںڰ��з���һ�����С�  ��....������......\n"NOR, me);
				me->receive_damage("kee",50);
				me->set_temp("last_damage_from","����Դ���ﱻС����ҧ���ˡ�\n");
				break;
		}
	return 1;
}

void light_notify(object obj, int i)
{
    object *inv, me, room;
	int j;
	
	me = this_player();
	switch (i) { 
	case 0:
        message("vision","�ڰ��д������Ǽ������ߡ�ӵ�������\n" , environment(me), me);
		tell_object(me, obj->name() + "�ƺ���ˮ��ʪ�������ˡ�\n");
		break;
	case 1:
        message_vision(obj->name() + "�����Ĺ������˵ص���\n\n" , me);
		room = find_object(__DIR__"ltunnel");
        if(!objectp(room)) room=load_object(__DIR__"ltunnel");
		inv = all_inventory(this_object());
		for(j=0; j<sizeof(inv); j++) {
        	inv[j]->move(room);
		}
		break;
	}
}
