inherit __DIR__"tutor";
#include <ansi.h>
void create()
{
        set_name("�����ϵĲ���", ({ "pingfeng","����", "screen" }));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "���������в�����һ�״ʡ�\n"+YEL" 
             ����Ū�ɣ����Ǵ��ޣ�
             �����������ȡ�
             �����¶һ��꣬
             ��ʤȴ�˼�������
             
             ������ˮ���������Σ�
             �̹�ȵ�Ź�·��
             �������Ǿó�ʱ��
             �����ڳ���ĺĺ��\n" NOR"\n\n     ���������д�������֮�⣬�������Ƿ��ŵ��⾳��\n");
 		set("no_shown", 1);
 		set("no_get",1);
 		set("teaching", "throwing");
 		set("teaching_limit", 400);
 	}
 	
 }
