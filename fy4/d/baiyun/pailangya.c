//Sinny@fengyun 2003
//All Rights Reserved
#include <ansi.h>

inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
�������β��ϵس������ʯ���˻��ɽ�������������֮�£�����ǧ���⣬Զ��
Ҳ�ǹ�����㣬�����޼ʣ�εΪ��ۡ��쪵ĺ������ʯ�����˵����ǣ�����������
��������뺣��Լ������ʮ�ɣ����Ǹ��ͣ������仹�и��ߵ���ʯ�ͱڣ���������վ
����һ��޴����ʯ��֮ʱ���������ϵĸ��Ʊ������֮�⣬����ŸҲ���ٷ�������
�����Ŵ󺣡��˻�����Ÿ�������к��鼤������Ѫ��С�;
LONG
    );
    set("exits",
      ([
	"southup" : __DIR__"jintaoting",
	"northwest" : __DIR__"baiyunentrance",
	"east" : __DIR__"shiliang",
      ]));
    set("objects",
      ([
	//	     __DIR__"obj/sand" : 1,
      ]));
/*    set("item_desc", ([
	"��ʯ" : "��һ�����ʯ�ѱ�������˻��Ĵ�İ�ವ��������ʯ�������ɼ���ʮ������
���µĽ�ӡ���ƺ�����һ�ײ���������԰��Ž�ӡģ������һ�¡�\n",
      "rock" : "��һ�����ʯ�ѱ�������˻��Ĵ�İ�ವ��������ʯ�������ɼ���ʮ������
���µĽ�ӡ���ƺ�����һ�ײ���������԰��Ž�ӡģ������һ�¡�\n",
   ]));*/

    set("outdoors", "baiyun");
 	set("coor/x",10);
  	set("coor/y",-30);
	set("coor/z",0);
	setup();
}


void init()
{
//   add_action("do_imitate", "imitate");
}


int do_imitate(string arg)
{
        object me;
        int  s, amount, da, agi;
        if (this_player()->query("class")!="baiyun")
                return notify_fail("����ҵĲ��˼��ţ�ʲôҲû����ᡣ������\n");
        me = this_player();
        if( me->is_fighting() )
                return notify_fail("��ս������ϰ����������\n");
        if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ�����ģ�¡�\n");
        s = (int)me->query_skill("feixian-steps", 1);
        agi = me->query_agi();
        if(agi == 10) {
                agi = agi + 2;
        }
        if( random(agi) >= 10) 
        {
                if(s >= 30)   {
                        message_vision(HIW "\n$N�Ų�ӡ�ǣ�������磬��˿�����ͣ�Ʈ������.\n"NOR, me);
                        tell_object(me, HIR"\n��ķ��ɲ����Ѿ��޷����˾����ˡ�\n"NOR);
                        return 1;
                } 
                da = 30*20/(me->query("dur")+me->query("fle"));
                if (me->query("kee") - da <= 1 || me->query("gin") - da <= 1 || me->query("sen") - da <= 1)
                {
                  return notify_fail("�������ڵ�״̬���޷�������\n");
                }
                if(s >= 0)   {
                        message_vision(HIW"\n$N�Ų�ӡ�ۣ��������У����������½�ӡ��ǰ�����⽥ͨ���Ų�Ҳ�𽥼ӿ���������\n"NOR, me);
                } else    {
                        message_vision(HIW"\n$N�Ų�ӡ�ۣ�ȴ���÷����Ť����֪�����̤����һ����\n"NOR, me);
                        }
                tell_object(me, HIY"��ķ��ɲ���������һЩ��\n"NOR);
                amount =  ((me->query("int") + me->query("cps"))*10);
                if(amount < 1) amount = 1;
                me->improve_skill("feixian-steps", amount);
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

          message_vision(BLU"\n$N��̤ӡ�ۣ�����ȴ���ش�һ���Ĵ�����������㱼䣬����һ�գ�ˤ���ڵء�\n"NOR, me);
                me->receive_damage("kee", da);
                me->receive_damage("gin", da);
                me->receive_damage("sen", da);
                }
        me->start_busy(2);
        return 1;
}
