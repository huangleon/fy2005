//XXDER
inherit ITEM;
void create()
{
        set_name("ս��", ({ "letter", "ս��"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
				set("long",
"һ���ź����ƺ����Դ�(open)������\n"
);
				set("keke",1);
        }
  ::init_item();
}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","open");
}

 
int do_open(string arg)
{
	if (!arg) return notify_fail("�����ʲô��");
	if (arg!="letter") return notify_fail("�Ǹ��������ܴ�");
	message_vision("$N����$p�������ó���һ���ţ�����д�ţ�
���� ��Ԫҹ��ʱ��
�ص㣺��լ��
�������÷ɵ�����������
ʤ����һ�м�ɶ�ʤ������������ɶ���
��ս�ˣ����ݡ�Ѧ��\n",this_player(),this_object());
	if (!this_player()->query("marks/͵���ɿɵ���"))
	{
		this_player()->add("score",-100);
		this_player()->set("marks/͵���ɿɵ���",1);
	}
	return 1;
}

