inherit ITEM;
void create()
{
        set_name("��Ů��", ({ "sunvjing" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","
�ݺ��˿�֤����Ů����������ս��������֮����ɣ�����κ�������������
�޸ĵġ�������������ڽ�����������ġ���������ƪ.��������,���߲��ꡣ
����ԭ��ʧ�������������ֶ�孵���������982���ɵġ�ҽ�ķ���һ������
�ռ����飬���������������ġ���Ů�������ǡ�ҽ�ķ������ռ����������
Ҷ�»Լ��롶˫÷�������顷��\n" );
                set("value", 260);
                set("material", "paper");
        }
	::init_item();
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_study","study");
}


int do_study(string arg)
{
        object me,ob;
	int sena;
	int cps;
	string book;
	string *content = ({
"
�Ƶ�����ŮԻ��������˥�����ͣ����ڲ��֣�����Σ������֮�Σ���
��ŮԻ��������֮����˥΢�ߣ���������������֮��������Ů֮ʤ�У���ˮ֮
���֪��֮���縪���ܺ���ζ���Գɸ�������֪����֮����Ϥ�����֣���֪
֮�ߣ�������ز���εû��֣��ɲ����գ�\n\n",
"
��ŮԻ�����в�Ů�ߣ���õ�������ʹ��Ů�ʣ�������������֮��������Ի��
���������񣬷�ʳ��ҩ���ɵó�����Ȼ��֪����֮�������ҩ����Ҳ����Ů��
�ɣ����������Ҳ����صý���֮���������վ�֮�ޡ���ʧ����֮��������ز
��֮�����ܱܽ���֮�¶�������֮��������֮��Ҳ����\n\n",
"
�Ƶ�Ի�������������ӣ��ڶ�Ϊ֮�κΣ�����ŮԻ��������֮����������״��
���²�˥��Ů���ٲ����������֣�����ǿ��Ȼ��֪���ߣ�����˥����֪�����
���ڶ��������ġ���־����������������ͳ�飬�������ȣ���������������
�壬�Ա���٣�ǳ���춯��������ϣ��Ů���⣬��ʢ��˥���Դ�Ϊ�ڡ���\n\n",
});		

        me = this_player();
	cps = random((int)me->query("cps"));
       if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
                return notify_fail("ָ���ʽ��study <��> <������>\n");
        if( (string) book != "sunvjing")
                return notify_fail("��Ҫ��ʲ�᣿\n");
        if(!objectp(ob = present(book, me)) )
                return notify_fail("��Ҫ��ʲ�᣿\n");
       switch( random(3) ) {
                case 0:
        message("vision", me->name() + "����ϲ����ط�����" + ob->name()
                + "��\n", environment(me), me);
                        break;
                case 1:
        message("vision", me->name() + "����һҳ" + ob->name()
                + "��̧��ͷ��ɫ���������������µĴ������㡣\n", environment(me), me);
                        break;
                case 2:
        message("vision", me->name() + "�ɿ�ط�����" + ob->name()
                + "����ž����һ����һ�ο�ˮ�������ϡ�\n", environment(me), me);
                        break;
        }
		write(content[random(sizeof(content))]);
	if( cps >20 )
	{	write("��Խ��Խ���������\n");
		return 1;
	}
	if( cps >15)
        {       write("��е�ȫ���ȣ�Խ��Խ���������\n");
                return 1;
        }
		write("��е�һ�������ӵ���ֱ�����𣮣���\n");
		me->unconcious();
		return 1;
}


