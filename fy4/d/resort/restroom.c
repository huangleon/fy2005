
#include <ansi.h>
inherit ROOM;

void create()
{
     set("short", "÷��С��");
     set("long", @LONG
�������ٷ�ЪϢ�ĵط���������ʰ��һ����Ⱦ������ѩ����ȴ�տյ���û
ʲô���裬����ǽ�Ϲ���һ��������������ѩ����ġ�ѩ÷��˪ͼ���⣬��ֻ��һ
��������ʯ���������ٷ����߽�����ѩ�����������ˣ��������Σ�����̤��
���ģ����������������ٵ������ڼ����ຮ֮�صĺ���ʯΪѩ������ˡ�
LONG
        );
    	set("exits", ([ 
  			"west" : __DIR__"bamboo_hall",
		]));

    	set("item_desc", ([
      		"����ʯ": "һ�鳤���������ʯ������ֻ�����Ų�ϯ��һ���ײ������������������(laydown)�����档\n",
      		"�����ʯ": "һ�鳤���������ʯ������ֻ�����Ų�ϯ��һ���ײ������������������(laydown)�����档\n",
      		"��ʯ": "һ�鳤���������ʯ������ֻ�����Ų�ϯ��һ���ײ������������������(laydown)�����档\n",
      		"jadebed": "һ�鳤���������ʯ������ֻ�����Ų�ϯ��һ���ײ������������������(laydown)�����档\n",
   		]) );
    	set("no_magic", 1);
		set("coor/x",20);
		set("coor/y",0);
		set("coor/z",0);
		setup();
}

void init()
{
	add_action("do_laydown", "laydown");
//	add_action("do_exercise","exercise");
}

int do_laydown()
{
	object me = this_player();
	if (me->query_temp("in_bed"))
	{
		return notify_fail("���ڴ����ء�����\n");
	}
	message_vision("$N�������ں����ϡ�\n",me);
	me->set_temp("in_bed", 1);
	tell_object(me,"��ֻ�����Ǳ������������ˡ�\n");
	call_out("curePlayer",5,me);
	return 1;
}

void curePlayer(object me)
{
	if (!me) return;
	me->set_temp("in_bed", 0);
	if (environment(me) == this_object())
	{
		tell_object(me,WHT"���������ú�����ȥ���о���ͷ������ů������֮����Ϣ��ת��ͣ��\n "NOR);
		if(me->query("eff_kee") != me->query("max_kee"))
		{
			tell_object(me,"�����ϵ����ƾ������غ��ˣ�\n");
			me->set("eff_kee",me->query("max_kee"));
			me->status_msg("kee");
		}
		message_vision("$N�Ӵ��ϻ���������������չһ�½�ǣ�������ˡ�\n",me);
/*		if (me->query("class") == "legend")
		{
			me->set_temp("marks/FastenExec",1);
			//need to give tiexue dizi any hint that they can exercise here and get double effect?
		}	*/
	}
}

/*
int do_exercise(string arg)
{

	int kee_cost=30, force_gain;
	int ratio = 2;
	object me=this_player();

	if (!(me->query_temp("marks/FastenExec"))) return 0;

      	seteuid(getuid());
        
    	if( me->is_fighting() )
        	return notify_fail("ս���в������ڹ������߻���ħ��\n");
    	if( me->is_busy() )
        	return notify_fail("����һ��������û����ɣ��������ڹ���\n");
    
    	if( !stringp(me->query_skill_mapped("force")) )
        	return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");
    
    	if( arg && !sscanf(arg, "%d", kee_cost) )
        	return notify_fail("��Ҫ��������������\n");

    	if( kee_cost < 10 ) return notify_fail("������Ҫ�� 10 �㡸��������������\n");

    	if( (int)me->query("kee") < kee_cost )
        	return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");

    	if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
        	return notify_fail("�����ھ���״��̫���ˣ��޷�����רһ��\n");

    	if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
        	return notify_fail("�����ھ����������޷�������Ϣ��������\n");

    	write("�㰵������������һƬ��������Ϣ��ת�������죬ȴ��ƽ��ͨ�����������泩�ޱȡ��� \n");

    	me->receive_damage("kee", kee_cost);
    	me->start_busy(1);
        // This function ranged from 1 to 15 when kee_cost = 30
    	force_gain = kee_cost * ((int)me->query_skill("force")/10
                             + (int)me->query_con() ) / 30;
    	force_gain = (force_gain + random(force_gain))/2;
	
	//what exactly double effect mean? -- change to 3/2
	force_gain = ratio * force_gain * 3/4;

    	if( force_gain < 1 ) {
        	write("���ǵ����й���ϣ�ֻ����ȫ���顣\n");
        	return 1;
    	}

    	me->add("force", force_gain );
    
    	if( (int)me->query("force") > (int)me->query("max_force") * 2) {
        if( (int)me->query("max_force") >= 
            ((int)me->query_skill("force", 1) + 
             me->query_skill("force")/5) * 5 ) {

            write("�������Ϣ�鲼ȫ����ʱȴû�й��������ļ����ƺ�������Ϊ�Ѿ�������ƿ����\n");
	} else {
            write("���������ǿ�ˣ�\n");
            me->add("max_force", 1);
        }
        me->set("force", me->query("max_force"));
    }       
    return 1;	
    
}
*/

int valid_leave(object me, string dir)
{
	if (me->query_temp("in_bed")) 
	{
		remove_call_out("curePlayer");
		me->set_temp("in_bed", 0);
	}
	return 1;
}

