
inherit ITEM;

void create()
{
        set_name("�����˵�ֽ", ({ "yellow paper", "paper", "ֽ"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���Ѿ������˵�ֽ��������ּ���ȱ��ȫ������Լ�ɱ�
	��Դ                   
                      ����    ˮ�� 
�����֡�
\n");
                set("value", 1);
        }
}

void init()
{
   add_action("do_remember", "remember");
}

int do_remember(string arg)
{
   object me;

   me = this_player();

   if (!arg || (arg != "yellow paper" && arg != "�����˵�ֽ"))
      return 0;
   else {
      tell_object(me, "�������������Դ�����أ�ˮ���⼸���֣������εؼ��������\n");
      me->set_temp("marks/cangbao",1);
      return 1;
   }
   return 0; 
}
