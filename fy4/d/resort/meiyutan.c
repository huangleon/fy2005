
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "÷��̶");
        set("long", @LONG
��ɽׯ��Ժ�߳���ɽ�����������𽥻�۳��ļ��������ٲ�����������÷��
ï�ܣ��������ˡ�ÿ������֮ʱ������ˮ���ݷ����÷�꣬�����޷����ɻ������
�ҽ����ǽ��ŵ�ˮ������Ө����â��ԶԶ��ȥ����һ���СС�İ�÷��΢���Ƶķ�
�����š��ʴ˳�֮Ϊ÷���٣���ˮ����۳�����һ�̵�÷��̶��
LONG
        );
        set("exits", ([ 
  		"southup" : __DIR__"back_yard",
	]));
       set("objects", ([
        ]) );
        set("outdoors", "resort");
   	set("item_desc", ([
      	"÷����" : "÷�������������飬�Ƴ���÷�꣬�ʳ�÷���١���ֵ�꼾���ٲ�ˮ��ʮ���ļ���\n",
      	"waterfall" : "÷�������������飬�Ƴ���÷�꣬�ʳ�÷���١���ֵ�꼾���ٲ�ˮ��ʮ���ļ���\n",
   	]));
	set("resource/water", 1);
	set("liquid/container", "÷��̶");
	set("liquid/name","÷��̶ˮ");
	set("tiexue_juhan",1);
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",-20);
	setup();
}

/*
void init()
{
   add_action("do_boji", "boji");
}


int do_boji(string arg)
{
   	object me;
   	int  s, amount, da, cor;
   	if (this_player()->query("class")!="legend")
   		return notify_fail("��ʲôҲû���������������\n");
   	if(!arg || arg != "blade" ) return notify_fail("��Ҫ��ϰʲô���ܣ�\n");
   	me = this_player();
   	if( me->is_fighting() )
      		return notify_fail("��ս������ϰ����������\n");
   	if( me->is_busy() )
      		return notify_fail("����һ��������û����ɣ����ܲ�����\n");
   	s = (int)me->query_skill("blade", 1);
   	cor = me->query_cor();
   	if(cor == 10) {
		cor = cor + 2;
	}
   	if( random(cor) >= 10) 
   	{
      		if(s >= 100)   {
         		message_vision(HIC "\n$N����Ծ��÷���٣�������Ϣ�������뼱���࿹��\n\n������������˳��������ֻ��$N�޲�������졣\n"NOR, me);
         		tell_object(me, HIY"��Ļ��������Ѿ��޷����˾����ˡ�\n"NOR);
         		return 1;
      		} 
	  	da = 30*20/(me->query("dur")+me->query("fle"));
	  	if (me->query("kee") - da <= 1 || me->query("gin") - da <= 1 || me->query("sen") - da <= 1)
	  	{
		  return notify_fail("�������ڵ�״̬���޷�������\n");
	  	}
      		if(s >= 0)   {
         		message_vision(HIC"\n$N����Ծ��÷���٣�������Ϣ�����ص��\n\n$N�������У�˫������վ���������뼤������\n"NOR, me);
      		} else 	  {
         		message_vision(HIC"\n$N����Ծ��÷���٣�������Ϣ�������뼱���࿹��\n\n��ɽ�ٱ���$N��ҡ�һΣ����վ�ȡ�\n"NOR, me);
      			}
      		tell_object(me, HIY"��Ļ�������������һЩ��\n"NOR);
      		amount =  ((me->query("int") + me->query("cps"))*10);
      		if(amount < 1) amount = 1;
      		me->improve_skill("blade", amount);
      		me->receive_damage("kee", da);
      		me->receive_damage("gin", da);
      		me->receive_damage("sen", da);  
   	} else 
   	{
	  da = 200*20/(me->query("dur")+me->query("fle"));
	  if (me->query("kee") - da <= 1 || me->query("gin") - da <= 1 || me->query("sen") - da <= 1)
	  {
		  return notify_fail("�������ڵ�״̬���޷�������\n");
	  }

	  message_vision(CYN "\n$N˫��һ��ˮ������ˮ���ļ��쳣�޷����㣬��ͷһ���¡�\n"NOR, me);
     	  message_vision(CYN"\n$N����һ�飬����������̶�ߡ�\n"NOR, me);
//      		write("da is"+(string)(da)+".\n");
      		me->receive_damage("kee", da);
      		me->receive_damage("gin", da);
      		me->receive_damage("sen", da);
   		}
   	me->start_busy(3);
   	return 1;
}
*/