inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "����ʯ��");
        set("long", @LONG
ʯ�ҵ������ŷ���һ��һ�������ӡ�ʯ�ŵĶ���Ҳ��һ��ʯ�ڣ�ʯ�ڵ����ж�
���ڰ��ݣ�һ�ɿ����������з���һ��ʯ̳��֮����һ��ʯ��ʯ�����Ǳ�����ӳ
���˱���ɫ���̹��൱ϸ�£�ʯ������������һ�������ǻ�����֡�
LONG
        );
        set("exits", ([ 
		"north": __DIR__"stoneroom",
	]));
	set("no_fly",1);
        set("objects", ([
        	__DIR__"npc/daniang2": 1,
    	]) );
        
        set("item_desc", ([
		"����": "������״���ţ���̾��£����Ƕ��������������һ�㸻���˼����С�ֻ��
���ӵı��棬��֪����ֵ���ơ�����������������װ�ص����Ǻε����Ķ�����\n",
		"box": "������״���ţ���̾��£����Ƕ��������������һ�㸻���˼����С�ֻ��
���ӵı��棬��֪����ֵ���ơ�����������������װ�ص����Ǻε����Ķ�����\n",
	 ]));
	set("coor/x",110);
	set("coor/y",-30);
	set("coor/z",-20);
	set("map","taiping");
	setup();
}



void init() {
	
	add_action("do_look","look");
}



int do_look(string arg) {

	object me;
	me=this_player();
	
	if (arg=="ʯ��" || arg =="statue") {
		me->start_busy(10000);	
		tell_object(me,"ħ��֮ħ����ħ֮����ħ����ʯ����������¥Ѫū�����Ƿ�ħ���ϻ��ŵ��Ǹ�ͷ
���Ͻ�ڣ���Ӣ�����º͵�����ħ��������ü��䣬������һ��Ī������į��\n");	
		
		if (REWARD_D->riddle_check(me,"�Ѫ����")!=13 && !REWARD_D->check_m_success(me,"�Ѫ����")){
			tell_object(me,"ʯ���ƺ����˻Σ��������۾������ǿ����ˡ�����\n");
			return 1;	
		}
		me->set_temp("disable_inputs",1);
        me->set("disable_type",HIW "<������>" NOR);
		call_out("event1",1,me,0);
		return 1;
	}
	return 0;
}	


string *event1_msg=	({
	HIG"\n\n  ħ����������ͫͻȻ���������ᡣ��Ө�����ᣬ���̵Ļ������˸�ű��̵Ĺ�â��\n",

 	HIG"  ����ɫ����⡣���������񣬾�Ө�����ᡣ�������Ķ������ˡ�\n"NOR,

    	HIG"  ����������۾�ȴ��û�б仯��һգҲ��գ��ͫ��Ҳһ���������·������ᡣ\n"NOR,
	
	HIG"  һ˫�������ͫ�����̵Ļ����ҫ�����ѱ��̣�è�۰����⡣\n"NOR,

	WHT"  ʯ���Ȼ�ڸ������������̣���������\n"NOR,

    	WHT"  ����һɲ�ǣ�����ʯ������һ��ɢ������ʧ��\n"NOR,

    	YEL"  վ����ʯ�񷽲�վ���ĵط�����һ�����ˡ�\n"NOR,

	YEL"  �Ͻ����ڣ�Ӣ�����ºͣ�����˲���������¥Ѫū�����Ƿ�ħ��֮�������ŵ���
����������ʮ����ħȺ����Ĥ�ݣ�Ѫ����չ��������Ͷ��ħ��֮ħ����ħ֮����\n"NOR,

    	HIR"                                 ħ����\n"NOR,

	YEL"  ����ɫ�Ļ���֮�£�����ȫû�б��̡����ֱ���ɫ�Ĺ�â�����������䵽�������ϡ�
�������������������Ҳ��һ��������Ц��Ц��������߹�\n"NOR,

        YEL"  ħ�����ѿ���������ģ�Ц�ź�Ȼ��������֪���������кܶ������޷��������ħ
�������ֵ����������֪��Ѫ���ĵ����ܣ�����������������Ů�ӣ�ȴ�ִ���һ��
���Կ��ܵ����ϡ��㲻֪�����ص�ͷ��\n"NOR,

	YEL"  ħ��ת�����������ʯ���߹�ȥ���㲻�������ظ��������\n"NOR,


});


void event1(object me, int count)
{
	if (!me)	return;
		
	if (environment(me)!=this_object()) {
		me->delete_temp("disable_inputs");
        me->delete("disable_type");
		return;
	}
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
			tell_object(me,YEL"  ħ���Ų���ͣ����������ʯ��֮�ڡ���Ӳ��ͷƤ��һ��������ǽ�ڿ���ȥ��
��ֻ�ž�Ȼ����׾ٵ�һֱ�����ǽ��֮�ڡ�\n\n"NOR);
		me->stop_busy();
		me->delete_temp("disable_inputs");
        	me->delete("disable_type");
        	me->move(AREA_TAIPING"dream1");
        	me->unconcious();
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}


