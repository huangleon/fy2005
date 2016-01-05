#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
һ��С·�������������졣·���Ա��Ƿ��ƳǵĻ��Ǻӣ��ӵ�����һ�߾���
�ߴ�ķ��Ƴǳ�ǽ�ˡ���������Կ�����ǽ��ֵ�ڵ�ʿ����վ�ڡ��ӵ��ϳ�������
�ݡ�΢�����һ����������Ϣ���Դӽ�Ǯ���ڷ��Ƴ��������Ժ���������˽���
�Ķ���������ÿ���峿���н�ʨ�ھֵĳ��ӴӴ�·����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
//  "south" :"/d/quicksand/huangyie0",
	"south" : __DIR__"fywest",
  	"northeast" : __DIR__"road2",
	]));
         set("objects", ([
        __DIR__"obj/grass" : 1,
                        ]) );
        set("butterfly", 0);
        set("outdoors", "fengyun");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);


        setup();
}

void reset()
{
	object con, item, *inv;
	::reset();
	if( con = present("grass",this_object()))
	if( inv = all_inventory(con))
	if( !sizeof(inv)){
		item = new(__DIR__"obj/quant");
		item->move(con);
	}	
}

void init() {
	mixed *local;
	object me;
	int i, dayTime;
	
	
	local = NATURE_D->get_current_time();
	i = NATURE_D->get_season();
    	dayTime = local[5];
	me = this_player();
//	write(sprintf("%d", i));
	if(query("butterfly")) {
		return;
	}
	if ((i == 1 || i == 2) && dayTime > 720 && dayTime < 900 ) {
		if(random(10) == 1 && !me->query("����A/����_����")) {
			message_vision("\nһֻ������$N��߷ɹ�������·�ߵ�Ұ���ϡ�\n\n", me);
			set("butterfly", 1);
			call_out("butterfly1", 5, me);
		} else if (random(10) > 5) {
			message_vision("\nһֻ������$N��߷ɹ���������Զ����\n\n", me);
		}
	}
}

int butterfly1(object me) {
	if (!me)	return 1;
	if(environment(me) == this_object()) {
		message_vision("\n����Խ��Խ�࣬·�ߵ����Ұ��֮�䣬��Ⱥ�ĺ������·��衣��"HIR"����ɫ��"NOR"��\n", 
				me);
		message_vision(HIB"����ɫ��"NOR"��"HIY"��ɫ"NOR"�������ڰߵģ�����ɫ����βƮ����....ÿһֻ�����ɹ���ǰ��\n",
				me);
		message_vision("��ʱ���㶼����ϸ����������ɵ�ͼ�����ƣ������ֺܿ챻�ɹ�������һֻ��\n",
				me);
		message_vision("Ư����������ע������\n", 
				me); 
		message_vision("\n�ڶ�ĺ����������ߵĲݴ�֮���������裬����Ŀҡ��ۡ�\n", me);
		call_out("butterfly2", 5, me);
	} else {
		set("butterfly", 0);
	}
}
int butterfly2(object me) {
	if (!me)	return 1;
	if(environment(me) == this_object()) {
		message("vision", HIY"\n��Ȼ����һֻ�ر�Ѥ��ҫ�۵ĺ�������������ߡ����ȱ�ĺ�����Ҫ��\n"NOR, 
				me);
		message("vision", HIY"��������͸��������˵����ʲô��ɫ�ģ���Ϊ������������ʱ�仯�ű�ʯ���ɫ�ʣ�\n"NOR,
				me);
		message("vision", HIY"Ҳ����˵����ʲôͼ�����ƺ���ǧ����������ͼ���ڲ�ͣ�Ļö��� \n"NOR,
				me);
		message("vision", "\n���ɹ�����������һ��Ʈ翵�Ӻ�ݡ������ε�Ʈ���У���о��������κ�\n",
				me);
		message("vision", "أͻ�Ķ��������еķ��й켣������һ�����������������ߡ�\n",
				me); 
		call_out("butterfly3", 5, me);
	} else {
		set("butterfly", 0);
	}
}

int butterfly3(object me) {
	if (!me)	return 1;
	if(environment(me) == this_object()) {
		message("vision", HIB"\n���̲�סռ�е�������������ŵĹ�ȥ�������׽����� \n"NOR,
				me);
		message("vision", me->name() + "�����������·�ߣ���Ҫ׽ʲô������\n", 
				environment(me), me);
		message("vision", "\n�����ͣ��һ��ٺϻ��ϵ�ʱ�����������ȥ... \n",
				me);
		message("vision", HIW"\n��ɫ�İٺϻ��ϣ���ɫ�����ĳ��һ��һ�ϣ����ͼ��������������һ���𺳣�\n"NOR,
				me);
		message("vision", HIW"��֪����������Զ����������\n"NOR,
				me);
		call_out("butterfly4", 3, me);
	} else {
		set("butterfly", 0);
	}
}

int butterfly4(object me) {
	
	int num = 1+ random(10);
	if (!me)	return 1;
	if(environment(me) == this_object()) {	 
		message("vision", "\n�������һ�£����Ƿɿ�����֣���ס�˺����ĳ��\n",
				me); 
		message("vision", HIM"\n���������ָ����������һ˲�䣬��ɫ������Ȼ�����Ƭ�����������ĩ��ɢ��... \n"NOR,
				me);
		message("vision", HIM"��ͬ�������羲ˮ��ĵ�Ӱ����ͬ������һ������ʱ�ֵĺ��Ρ�\n"NOR,
				me);
		message("vision", "\n�㲻�����ŵؿ�����һĻ�ķ�����������ֻ�������� \n",
				me);
		message("vision", HIG"\nû�з紵�ķ��衣���е���Ƭ���ϼ������ѣ��ɷ۳�ɰ���������������ű�õ��߲ʣ�\n"NOR,
				me);
		message("vision", HIG"��ͬ��˯����ʱ��ǰ���������ʡ�\n"NOR,
				me); 
		message("vision", me->name() + "ֱ������������վ��·�ߡ�����\n", environment(me), me);
		message("vision", HIC"��" + me->name() + "���һ��ϸ��ĩ������������±�������˵��߲ʡ�\n"NOR, 
				environment(me), me);
		message("vision", "\n����ȺѸ�ٵ�ɢȥ��\n",
				environment(me), me);
		set("butterfly", 0);	
		if (!me->query("����A/����_����")) {
			me->set("����A/����_����", num);
			log_file("riddle/FATE_LOG",
			sprintf("%s(%s) �õ�����A/����_���� "+num+"�� %s \n",
				me->name(1), geteuid(me), ctime(time()) ));
		}	
			
	} else {
		set("butterfly", 0);
	}
}