//Sinny@fengyun2003
//All Rights Reserved
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "ŭ��");
        set("long", @LONG
���������Ƶ��У�Ψ��ŭ����Ȼ������ֵˮ��֮�ʣ����˳�����Χ�Ľ�ʯ����ס
����ʹ���Ĳ��񵴣�������죬������һ�̷Ż����������ﳤ���ܿ���ʴ����ˮ��
ˢ�����Ҷ��ͣ�ʯɫ����Ľ�ʯΡȻ����������ŭ����ͷ������������������������
����ãã��ŭ�˾����в�ʱ�м�ֻ�����貫����ŭ�ˣ���ϼ�����졢�󺣡�ŸӰ��
�·������������֮�䣬������Ȼ���¡�
LONG
           );
        set("exits",
            ([
        "west" : __DIR__"shiliang",
	    ]));
	set("objects",
 	   ([
        __DIR__"obj/rock" : 1,
        __DIR__"npc/baiyunxian" : 1,
	    ]));
      set("item_desc", ([
      "ŭ��" : "ŭ�˵��Ĵ��Ž�ʯ��ʱ��ŭ���ţ���Х�ţ�ʱ����������ͬ����һ�㣬��ֻ��Ÿ����
������ŭ�ˣ���ϼ�����졢�󺣡�ŸӰ���·����㲻�ɼ�ĿԶ����������˼��\n",
      "����" : "ŭ�˵��Ĵ��Ž�ʯ��ʱ��ŭ���ţ���Х�ţ�ʱ����������ͬ����һ�㣬��ֻ��Ÿ����
������ŭ�ˣ���ϼ�����졢�󺣡�ŸӰ���·����㲻�ɼ�ĿԶ����������˼��\n",
      "wave" : "ŭ�˵��Ĵ��Ž�ʯ��ʱ��ŭ���ţ���Х�ţ�ʱ����������ͬ����һ�㣬��ֻ��Ÿ����
������ŭ�ˣ���ϼ�����졢�󺣡�ŸӰ���·����㲻�ɼ�ĿԶ����������˼��\n",
   ]));

        set("outdoors", "baiyun");
	set("coor/x",0);
	set("coor/y",-1030);
	set("coor/z",0);
	setup();

}

void init()
{
//   add_action("do_watch", "watch");
}


int do_watch(string arg)
{
        object me;
        int  s, amount, da, spi;
        if (this_player()->query("class")!="baiyun")
                return notify_fail("�㼫ĿԶ���������á�����֪����ˮ���Ǻ�ˮ��ʪ��˫�ۣ�һ��Ī���ĸж�
���˻��������ء�\n");
        me = this_player();
        if( me->is_fighting() )
                return notify_fail("��ս���п�����̫�������˰ɣ�\n");
        if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ����ܿ�����\n");
        s = (int)me->query_skill("painting", 1);
        spi = me->query_spi();
        if(spi == 10) {
                spi = spi + 2;
        }
        if( random(spi) >= 10) 
        {
                if(s >= 150)   {
                        message_vision(HIC "\n$N��ĿԶ�������ã���̾һ��������������أ�����һ�з·��������Ժ���һ�㡣\n"NOR, me);
                        tell_object(me, HIW"\n��Ļ����޷�������Ϊ�ˡ�\n"NOR);
                        return 1;
                } 
                if(s <= 120)   {
                        message_vision(HIW "\n$N��ĿԶ���������á�����֪����ˮ���Ǻ�ˮ��ʪ��˫�ۣ�һ��Ī���ĸж�
��ӯ���أ����޷����Ƹ��ˣ�ʧ��ʹ�ޡ�\n"NOR, me);
                        tell_object(me, HIW"\n����Ϊ��ǳ���޷��Թۺ��������\n"NOR);
                        return 1;
                } 
                da = 30*20/(me->query("dur")+me->query("fle"));
                if (me->query("kee") - da <= 1 || me->query("gin") - da <= 1 || me->query("sen") - da <= 1)
                {
                  return notify_fail("�������ڵ�״̬���޷��ۺ���\n");
                }
                if(s >= 0)   {
                        message_vision(HIW"\n$N��ĿԶ����ŭ�ˣ���ϼ�����졢�󺣡�ŸӰ���·���������ؼ����һ��׳��
���ã���񲻾���һ�������Ļ���\n"NOR, me);
                } else    {
                        message_vision(HIW"\n$N������˼���࣬���Ծ����Թۺ���\n"NOR, me);
                        }
                tell_object(me, HIY"��Ի����ƺ�����Щ����\n"NOR);
                amount =  ((me->query("int") + me->query("spi"))*10);
                if(amount < 1) amount = 1;
                me->improve_skill("painting", amount);
                me->receive_damage("kee", da);
                me->receive_damage("gin", da);
                me->receive_damage("sen", da);  
        } else 
        {
          da = 200*20/(me->query("dur")+me->query("fle"));
          if (me->query("kee") - da <= 1 || me->query("gin") - da <= 1 || me->query("sen") - da <= 1)
          {
                  return notify_fail("�������ڵ�״̬���޷����Ĺۺ���\n");
          }

          message_vision(BLU"\n������ӿ������絶��$N��ս�ľ�֮�£�վ�����ȣ���������ʯ�ϡ�\n"NOR, me);
                me->receive_damage("kee", da);
                me->receive_damage("gin", da);
                me->receive_damage("sen", da);
                }
        me->start_busy(3);
        return 1;
}
